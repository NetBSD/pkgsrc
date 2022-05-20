/*
 * This code is derived from xcin-chewing-20041004.diff and
 * rewritten by Rui-Xiang Guo to use the new libchewing APIs.
 *
 * Bridge interface between libchewing and xcin
 */

#ifdef HAVE_CONFIG_H
#  include "config.h"
#endif

#include <chewing/chewing.h>
#include <string.h>

#include <X11/Xlib.h>
#include <X11/keysym.h>
#include "xcintool.h"
#include "module.h"

#include <iconv.h>
#include <langinfo.h>

/* the following keystate masks are defined by xcin */
#define CAPS_MASK (2)
#define CTRL_MASK (4)

#define XCIN_BYTE_NATIVE 	2
#define XCIN_BYTE_UTF8 		3

/* internal/chewing-private.h */
#define MAX_UTF8_SIZE		4
#define BOPOMOFO_SIZE		4
#define AUX_PREFIX_LEN		(3)	/* showMsg */
#define MAX_PHRASE_LEN		11
#define MAX_PHONE_SEQ_LEN	50	/* commitBuf */
#define MAX_CHOICE_BUF		(50)	/* max length of the choise buffer */

static char *cname;
static char *kb_type_str;

static int chewing_codeset;
static int chewing_mbs_wcs(wch_t *wcs, char *mbs, int wcs_len);
void preconvert(const char *input, char *output, int n_char);

static char selKey_define[11] = "1234567890\0"; /* Default */

int MakeInpinfo(inpinfo_t *inpinfo);

static int
ChewingInit(void *conf, char *objname, xcin_rc_t *xc)
{
	char *cmd[2], value[50];
	int i;
	ChewingConfigData *cf = (ChewingConfigData *) conf;

	putenv("CHEWING_PATH=" CHEWING_DATA_PREFIX);

	/* For compatible purposes */
	cf->candPerPage = 9;
	cf->maxChiSymbolLen = 16;

	/*
	 * The new libchewing uses UTF-8 encoding for all its structure
	 * so we need to check if it is UTF-8 locale and do any conv
	 */
	chewing_codeset = (!strcasecmp(xc->locale.encoding, "utf-8")) ?
		XCIN_BYTE_UTF8 :
		XCIN_BYTE_NATIVE;
	cname = (char *) calloc(3, sizeof(char) * chewing_codeset);

	cmd[0] = objname;
	/* Set keyboard type */
	cmd[1] = "KB_TYPE";
	kb_type_str = "KB_DEFAULT";
	if (get_resource(xc, cmd, value, 50, 2)) {
		kb_type_str = value;
	}

	/* Support selection key definitions */
	cmd[1] = "SELECTION_KEYS_DEFINE";
	if (get_resource(xc, cmd, value, 50, 2)) {
		if (strlen(value) == 10) {
			strcpy(selKey_define, value);
			selKey_define[11] = '\0';
		}
	}
	for (i = 0; i < 10; i++)
		cf->selKey[i] = selKey_define[i];

	/* Set phrase direction */
	cmd[1] = "ADD_PHRASE_FORWARD";
	cf->bAddPhraseForward = 0;
	if (get_resource(xc, cmd, value, 50, 2)) {
		if (atoi(value) == 1) {
			cf->bAddPhraseForward = 1;
		}
	}

	return True;
}

static int 
ChewingXimInit(void *conf, inpinfo_t *inpinfo)
{
	static char cchBuffer[MAX_PHONE_SEQ_LEN * MAX_UTF8_SIZE + 1];
	ChewingConfigData *cf = (ChewingConfigData *) conf;
	int i;

	/* Initialize Chewing */
	inpinfo->iccf = chewing_new();

	/* CallSetConfig */
	chewing_set_candPerPage(inpinfo->iccf, cf->candPerPage);
	chewing_set_maxChiSymbolLen(inpinfo->iccf, cf->maxChiSymbolLen);
	chewing_set_KBType(inpinfo->iccf, chewing_KBStr2Num(kb_type_str));
	chewing_set_selKey(inpinfo->iccf, cf->selKey, 10);
	chewing_set_addPhraseDirection(inpinfo->iccf, cf->bAddPhraseForward);

	inpinfo->lcch = (wch_t *) calloc(MAX_PHONE_SEQ_LEN, sizeof(wch_t));
	inpinfo->lcch_grouping = (ubyte_t *) calloc(MAX_PHONE_SEQ_LEN, sizeof(ubyte_t));
	inpinfo->cch = cchBuffer;

	preconvert("\xE6\x96\xB0\xE9\x85\xB7\xE9\x9F\xB3", cname, 9);
	inpinfo->inp_cname = cname;
	inpinfo->inp_ename = "chewing";
	inpinfo->area3_len = 2 * BOPOMOFO_SIZE + 4;
	inpinfo->guimode = GUIMOD_LISTCHAR | GUIMOD_SELKEYSPOT;
	inpinfo->keystroke_len = 0;
	inpinfo->s_keystroke = (wch_t *) calloc(MAX_PHRASE_LEN + AUX_PREFIX_LEN, sizeof(wch_t));

	inpinfo->mcch = (wch_t *) calloc(MAX_CHOICE_BUF, sizeof(wch_t));
	inpinfo->mcch_grouping = (ubyte_t *) calloc(MAX_SELKEY, sizeof(ubyte_t));
	inpinfo->n_mcch = 0;

	inpinfo->n_lcch = 0;
	inpinfo->edit_pos = 0;
	inpinfo->cch_publish.wch = (wchar_t) 0;

	/*
	 * check_winsize(inpinfo, iccf);
	 * [yet] check winsize is under construction.
	 */

	inpinfo->n_selkey = 10;
	inpinfo->s_selkey = (wch_t *) calloc(MAX_SELKEY, sizeof(wch_t));

	for (i = 0; i < 10; i++) {
		inpinfo->s_selkey[i].wch = (wchar_t) 0;
		inpinfo->s_selkey[i].s[0] = selKey_define[i];
	}

	return True;
}

void CommitString(inpinfo_t *inpinfo)
{
	int len;
	char *str, *output;

	memset(inpinfo->cch, 0, sizeof(char) * (MAX_PHONE_SEQ_LEN * MAX_UTF8_SIZE + 1));
	str = chewing_commit_String(inpinfo->iccf);
	len = strlen(str);
	output = (char *) calloc(len, sizeof(char) * chewing_codeset);
	preconvert(str, output, len);
	strcat(inpinfo->cch, output);
	free(output);
}

static unsigned int 
ChewingXimEnd(void *conf, inpinfo_t *inpinfo)
{
	int rtn;

	/* if preedit exists, commit the string */
	chewing_handle_Enter(inpinfo->iccf);

	rtn = MakeInpinfo(inpinfo);
	chewing_delete(inpinfo->iccf);
	free(inpinfo->s_keystroke);
	free(inpinfo->lcch);
	free(inpinfo->mcch);
	free(inpinfo->mcch_grouping);

	inpinfo->iccf = NULL;
	inpinfo->s_keystroke = NULL;
	inpinfo->lcch = NULL;

	return rtn;
}      

void ShowChoose(inpinfo_t *inpinfo)
{
	int i = 1, len, pageno;
	char *buf, *output;
	const char *const_buf;

	memset(inpinfo->mcch, 0, sizeof(wch_t) * MAX_CHOICE_BUF);
	/*
	 * for new xcin, there is no need to modify the lcch buffer
	 * instead, we put phrase to choose in mcch
	 */
	if (chewing_cand_TotalPage(inpinfo->iccf) == 0)
		return;

	buf = (char *) calloc(MAX_CHOICE_BUF, sizeof(char) * chewing_codeset);
	chewing_cand_Enumerate(inpinfo->iccf);
	while (chewing_cand_hasNext(inpinfo->iccf)) {
		/* in the last page, no will exceed nTotalChoice */
		if (i > chewing_cand_ChoicePerPage(inpinfo->iccf))
			break;

		/* set grouping to the length of the phrase */
		const_buf = chewing_cand_String_static(inpinfo->iccf);
		inpinfo->mcch_grouping[i] = strlen(const_buf) / 3;
		strcat(buf, const_buf);
		i++;
	}

	/* i stores how many choices are available */
	inpinfo->mcch_grouping[0] = i;

	/* set pgstate according to the current page position */
	if (chewing_cand_TotalPage(inpinfo->iccf) == 1)
		inpinfo->mcch_pgstate = MCCH_ONEPG;
	else {
		pageno = chewing_cand_CurrentPage(inpinfo->iccf);
		if (pageno == 0)
			inpinfo->mcch_pgstate = MCCH_BEGIN;
		else if (pageno == (chewing_cand_TotalPage(inpinfo->iccf) - 1))
			inpinfo->mcch_pgstate = MCCH_END;
		else
			inpinfo->mcch_pgstate = MCCH_MIDDLE;
	}

	len = strlen(buf);
	output = (char *) calloc(len, sizeof(char) * chewing_codeset);
	preconvert(buf, output, len);
	inpinfo->n_mcch = chewing_mbs_wcs(inpinfo->mcch, output, (len + 1) * chewing_codeset);
	free(buf);
	free(output);
}

void ShowText(inpinfo_t *inpinfo)
{
	int len;
	char *output;
	const char *const_buf;

	memset(inpinfo->lcch, 0, sizeof(wch_t) * MAX_PHONE_SEQ_LEN);
	const_buf = chewing_buffer_String_static(inpinfo->iccf);
	len = strlen(const_buf);
	output = (char *) calloc(len, sizeof(char) * chewing_codeset);
	preconvert(const_buf, output, len);
	inpinfo->n_lcch = chewing_mbs_wcs(inpinfo->lcch, output, (len + 1) * chewing_codeset);
	free(output);
}

void ShowInterval(inpinfo_t *inpinfo)
{
	int i = 1;
	IntervalType it;

	if (chewing_buffer_Len(inpinfo->iccf) == 0) {
		inpinfo->lcch_grouping[0] = 0;
		return;
	}

	chewing_interval_Enumerate(inpinfo->iccf);
	while (chewing_interval_hasNext(inpinfo->iccf) == 1) {
		chewing_interval_Get(inpinfo->iccf, &it);
		inpinfo->lcch_grouping[i] = it.to - it.from;
		i++;
	}
	inpinfo->lcch_grouping[0] = i - 1;
}

void ShowStateAndZuin(inpinfo_t *inpinfo)
{
	int len;
	char *output;
	const char *const_buf;

	memset(inpinfo->s_keystroke, 0, sizeof(wch_t) * (MAX_PHRASE_LEN + AUX_PREFIX_LEN));
	if (chewing_aux_Check(inpinfo->iccf)) {
		const_buf = chewing_aux_String_static(inpinfo->iccf);
		len = strlen(const_buf);
	}
	else if (chewing_bopomofo_Check(inpinfo->iccf)) {
		const_buf = chewing_bopomofo_String_static(inpinfo->iccf);
		len = strlen(const_buf);
	}

	if (len > 0) {
		output = (char *) calloc(len, sizeof(char) * chewing_codeset);
		preconvert(const_buf, output, len);
		inpinfo->keystroke_len = chewing_mbs_wcs(inpinfo->s_keystroke, output, (len + 1) * chewing_codeset);
		free(output);
	}
}

int MakeInpinfo(inpinfo_t *inpinfo)
{
	int rtn = 0;

	if (chewing_keystroke_CheckAbsorb(inpinfo->iccf))
		rtn |= IMKEY_ABSORB;
	if (chewing_keystroke_CheckIgnore(inpinfo->iccf))
		rtn |= IMKEY_IGNORE;
	/* No function to check KEYSTROKE_BELL */
	if (chewing_commit_Check(inpinfo->iccf)) {
		rtn |= IMKEY_COMMIT;
		CommitString(inpinfo);
	}

	if (chewing_cand_TotalPage(inpinfo->iccf)) { /* in selection mode */
		ShowChoose(inpinfo);
		inpinfo->guimode &= ~GUIMOD_LISTCHAR; 
	}
	else {
		ShowText(inpinfo);
		ShowInterval(inpinfo);
		inpinfo->guimode |= GUIMOD_LISTCHAR;
	}

	ShowStateAndZuin(inpinfo);
	/* SetCursor */
	inpinfo->edit_pos = chewing_cursor_Current(inpinfo->iccf);

	return rtn;
}

static unsigned int
ChewingKeystroke(void *conf, inpinfo_t *inpinfo, keyinfo_t *keyinfo)
{
	KeySym keysym = keyinfo->keysym;
	int rtn;
	static KeySym last_key = 0;

	/* set Chinese / English mode by keystate */
	if (keyinfo->keystate & CAPS_MASK ) { /* uppercase */
		if (chewing_get_ChiEngMode(inpinfo->iccf) != SYMBOL_MODE)
			chewing_set_ChiEngMode(inpinfo->iccf, SYMBOL_MODE);
	}
	else {
		if (chewing_get_ChiEngMode(inpinfo->iccf) != CHINESE_MODE)
			chewing_set_ChiEngMode(inpinfo->iccf, CHINESE_MODE);
	}

	/* check no ctrl key was pressed */
	if (keyinfo->keystate >= 0 && !(keyinfo->keystate & CTRL_MASK ) && !(keyinfo->keystate & ShiftMask)) {
		switch (keysym) {
			case XK_Escape:
				chewing_handle_Esc(inpinfo->iccf);
				inpinfo->n_mcch = 0;
				break ;
			case XK_Return:
				chewing_handle_Enter(inpinfo->iccf);
				inpinfo->n_mcch = 0;
				inpinfo->s_keystroke->wch = (wchar_t) 0;
				break ;
			case XK_Delete:
				chewing_handle_Del(inpinfo->iccf);
				break ;
			case XK_BackSpace:
				chewing_handle_Backspace(inpinfo->iccf);
				break ;
			case XK_Up:
				chewing_handle_Up(inpinfo->iccf);
				break ;
			case XK_Down:
				chewing_handle_Down(inpinfo->iccf);
				break ;
			case XK_Left:
				chewing_handle_Left(inpinfo->iccf);
				break ;
			case XK_Right:
				chewing_handle_Right(inpinfo->iccf);
				break ;
			case XK_Home:
				chewing_handle_Home(inpinfo->iccf);
				break;
			case XK_End:
				chewing_handle_End(inpinfo->iccf);
				break;
			case XK_Tab:
				if (last_key == XK_Tab) /* double click TAB */
					chewing_handle_DblTab(inpinfo->iccf);
				else
					chewing_handle_Tab(inpinfo->iccf);
				break;
			case XK_Caps_Lock:
				chewing_handle_Capslock(inpinfo->iccf);
				break;
			case ' ': /* Space */
				chewing_handle_Space(inpinfo->iccf);
				break;
			default:
				chewing_handle_Default(inpinfo->iccf, keysym);
				inpinfo->n_mcch = 0;
				break;
		}
	}
	else if (keyinfo->keystate & ShiftMask) {
		switch (keysym) {
			case XK_Left:
				chewing_handle_ShiftLeft(inpinfo->iccf);
				break ;
			case XK_Right:
				chewing_handle_ShiftRight(inpinfo->iccf);
				break;
			default:
				chewing_handle_Default(inpinfo->iccf, keysym);
				inpinfo->n_mcch = 0;
		}
	}
	else if (keyinfo->keystate & CTRL_MASK) {
		if (keysym <= '9' && keysym >= '0') 
			chewing_handle_CtrlNum(inpinfo->iccf, keysym);
	}

	last_key = keysym;
	rtn = MakeInpinfo(inpinfo);

	return rtn;
}

static int 
ChewingShowKeystroke(void *conf, simdinfo_t *simdinfo)
{
	simdinfo->s_keystroke = NULL;

	return False;
}

static int
chewing_mbs_wcs(wch_t *wcs, char *mbs, int wcs_len)
{
	int len, i;
	char *s;

	for (s = mbs, len = 0; *s && len < wcs_len - 1; s += chewing_codeset, len++) {
		wcs[len].wch = (wchar_t) 0;
		for (i = 0; i < chewing_codeset; i++)
			wcs[len].s[i] = *(s + i);
	}
	wcs[len].wch = (wchar_t) 0;

	return len;
}

/* UTF-8 support */
void
preconvert(const char *input, char *output, int n_char)
{
	if (chewing_codeset == XCIN_BYTE_NATIVE) {
		const char *inptr = input;
		char *outptr = output;
		size_t inbytesleft = n_char;
		size_t outbytesleft = n_char / 3 * 2 + 1;
		iconv_t cd;

		cd = iconv_open("big5", "utf-8");
		iconv (cd, (const char **) &inptr, &inbytesleft, &outptr, &outbytesleft);

		iconv_close(cd);
	} else 
		strncpy(output, input, n_char);
}

static char zh_chewing_comments[] = 
	"Chewing : a smart phonetic input method module for XCIN.\n"
	"By Lu-chuan Kung <lckung@iis.sinica.edu.tw>,\n"
	"Kang-pen Chen <kpchen@iis.sinica.edu.tw>, and others.\n";

static char *zh_chewing_valid_objname[] = { "chewing", NULL };

module_t module_ptr = {
	{ 
		MTYPE_IM,
		"zh_chewing",			/* name */
		MODULE_VERSION,			/* version */
		zh_chewing_comments 
	},					/* comments */
	zh_chewing_valid_objname,		/* valid_objname */
	sizeof(ChewingConfigData),		/* conf_size */
	ChewingInit,				/* init */
	ChewingXimInit,				/* xim_init */
	ChewingXimEnd,				/* xim_end */
	ChewingKeystroke,			/* keystroke */
	ChewingShowKeystroke,			/* show_keystroke */
	NULL
};
