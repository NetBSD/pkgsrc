/*
 * This code is derived from xmbmon.c written by Yoshifumi R. Shimizu.
 *
 * Copyright (c) 2004 Rui-Xiang Guo
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <err.h>

#include <sys/envsys.h>
#include <sys/ioctl.h>
#include <sys/time.h>

#include <X11/Intrinsic.h>
#include <X11/StringDefs.h>

/* Fahrenheit flag used in get_values() */
int fahrn_flag = 0;

/* Label for showing or not showing a label */
char *label;

#define RES_NAME "xenvstat"

#define DEFAULT_GEOMETRY	"141x126"
#define DEFAULT_FONT		"-adobe-helvetica-bold-r-*-*-10-*-*-*-*-*-*-*"

#define DEFAULT_LBFONT		"-adobe-helvetica-bold-r-*-*-12-*-*-*-*-*-*-*"
#define DEFAULT_LBCOLOR		"black"

#define DEFAULT_COUNT		"4"
#define DEFAULT_SEC		"2"
#define DEFAULT_WSEC		"180"
#define DEFAULT_TMIN		"20.0"
#define DEFAULT_TMAX		"60.0"
#define DEFAULT_TMINF		"50.0"	/* for Fahrenheit */
#define DEFAULT_TMAXF		"130.0"	/* for Fahrenheit */
#define DEFAULT_VMIN		"1.80"
#define DEFAULT_VMAX		"2.20"
#define DEFAULT_TICK		"3"

#define DEFAULT_CLTCPU		"red"
#define DEFAULT_CLTMB		"blue"
#define DEFAULT_CLTCS		"cyan"
#define DEFAULT_CLFAN1		"gray"
#define DEFAULT_CLFAN2		"pink"
#define DEFAULT_CLVC		"green"

#define DEFAULT_CMTCPU		"CPU"
#define DEFAULT_CMTMB		"MB"
#define DEFAULT_CMTCS		"chip"
#define DEFAULT_CMFAN1		"fan1"
#define DEFAULT_CMFAN2		"fan2"
#define DEFAULT_CMVC		"Vc  "

#define DEFAULT_FAHRN		"False"

/* global variables */

/* temp1(CPU), temp2(MotherBoard), temp3(ChipSet), fan1, fan2, Vcore0 */
#define NUM_DATA 6

int nd = NUM_DATA;

char *font;

int width, height;

int count, sec, wsec;
int counter = 0;
int npoints = 0;
int range;

unsigned long ms;

float *fmean;

float tmin, tmax, vmin, vmax;
int tick;
float sscl, htck;

float cur_val[NUM_DATA] = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0};
char *l_color[NUM_DATA];
unsigned long cpix[NUM_DATA], d_cpix[NUM_DATA];

#define C_LBL 10

char ctmin[C_LBL], ctmax[C_LBL];
char cvmin[C_LBL], cvmax[C_LBL];

char *c_rdv[NUM_DATA], *c_rdg[NUM_DATA];
char *c_rdp[NUM_DATA] = {"%4.1f", "%4.1f", "%4.1f", "%4.0f", "%4.0f", "%4.2f"};

char *lb_font, *lb_color;
int h_lb = 0;

float scale[NUM_DATA];
float orign[NUM_DATA];
int x_rdg[NUM_DATA], x_rdv[NUM_DATA], y_rdg, y_rdv;
int cg_width[NUM_DATA], cv_width[NUM_DATA];
int h_cm, x_cm, y_cm;
unsigned long cpixlb, d_cpixlb;

typedef struct ring_data {	/* def. of ring-buffer */
	float val;
	struct ring_data *next;
} ring_d;

ring_d *rdp[NUM_DATA];
ring_d *rdpw[NUM_DATA];

int fd, ns;
envsys_tre_data_t *etds;

/* variables for X11 */

Widget wgt;
Display	*disp;
Window win;
GC gct, gclb, gcl[NUM_DATA];
XPoint *points;
XFontStruct *fontstr;
XFontStruct *lb_fontstr;

/* functions */

void usage(void);
void get_res(void);
void init_dt(void);
void getWH(int *width, int *height);
void repaint_proc(void);
void quit_proc(void);
void draw_values(void);
int ColorPix(Display *, char *, unsigned long *);
void alarm_handler(void);
int num_sensors(void);
int fill_sensors(void);
void get_values(void);
void calc_position(void);
void calc_scale(void);

/*---------- definitions of static data for X Toolkits ----------*/

	static String fallback_resources[] = {
		"*translations: #override \
			<Configure>: repaint_proc()\\n\
			<Expose>: repaint_proc()\\n\
			<BtnUp>: repaint_proc()\\n\
			<Key>Q: quit_proc()",
		"*geometry: "   DEFAULT_GEOMETRY,
		"*font: "       DEFAULT_FONT,
		"*count: "      DEFAULT_COUNT,
		"*sec: "        DEFAULT_SEC,
		"*wsec: "       DEFAULT_WSEC,
		"*tmin: "       DEFAULT_TMIN,
		"*tmax: "       DEFAULT_TMAX,
		"*vmin: "       DEFAULT_VMIN,
		"*vmax: "       DEFAULT_VMAX,
		"*tick: "       DEFAULT_TICK,
		"*cltcpu: "     DEFAULT_CLTCPU,
		"*cltmb: "      DEFAULT_CLTMB,
		"*cltcs: "      DEFAULT_CLTCS,
		"*clfan1: "     DEFAULT_CLFAN1,
		"*clfan2: "     DEFAULT_CLFAN2,
		"*clvc: "       DEFAULT_CLVC,
		"*cmtcpu: "     DEFAULT_CMTCPU,
		"*cmtmb: "      DEFAULT_CMTMB,
		"*cmtcs: "      DEFAULT_CMTCS,
		"*cmfan1: "     DEFAULT_CMFAN1,
		"*cmfan2: "     DEFAULT_CMFAN2,
		"*cmvc: "       DEFAULT_CMVC,
		"*fahrn: "      DEFAULT_FAHRN,
		"*label: "      ,
		"*labelfont: "  DEFAULT_LBFONT,
		"*labelcolor: " DEFAULT_LBCOLOR,
		NULL,
	};

	static XtActionsRec actions[] = {
		{"repaint_proc", (XtActionProc) repaint_proc},
		{"quit_proc", (XtActionProc) quit_proc},
	};

	static struct _app_res {
		char *font;
		int count;
		int sec;
		int wsec;
		float tmin;
		float tmax;
		float vmin;
		float vmax;
		int tick;
		char *cltcpu;
		char *cltmb;
		char *cltcs;
		char *clfan1;
		char *clfan2;
		char *clvc;
		char *cmtcpu;
		char *cmtmb;
		char *cmtcs;
		char *cmfan1;
		char *cmfan2;
		char *cmvc;
		Boolean fahrn;
		char *label;
		char *labelfont;
		char *labelcolor;
	} app_resources;

	static XtResource resources[] = {
		{"font", "Font", XtRString, sizeof(String),
			XtOffset(struct _app_res*, font),
			XtRString, (XtPointer) NULL},
		{"count", "Count", XtRInt, sizeof(int),
			XtOffset(struct _app_res*, count),
			XtRImmediate, (XtPointer) NULL},
		{"sec", "Sec", XtRInt, sizeof(int),
			XtOffset(struct _app_res*, sec),
			XtRImmediate, (XtPointer) NULL},
		{"wsec", "wSec", XtRInt, sizeof(int),
			XtOffset(struct _app_res*, wsec),
			XtRImmediate, (XtPointer) NULL},
		{"tmin", "Tmin", XtRFloat, sizeof(float),
			XtOffset(struct _app_res*, tmin),
			XtRImmediate, (XtPointer) NULL},
		{"tmax", "Tmax", XtRFloat, sizeof(float),
			XtOffset(struct _app_res*, tmax),
			XtRImmediate, (XtPointer) NULL},
		{"vmin", "Vmin", XtRFloat, sizeof(float),
			XtOffset(struct _app_res*, vmin),
			XtRImmediate, (XtPointer) NULL},
		{"vmax", "Vmax", XtRFloat, sizeof(float),
			XtOffset(struct _app_res*, vmax),
			XtRImmediate, (XtPointer) NULL},
		{"tick", "Tick", XtRInt, sizeof(int),
			XtOffset(struct _app_res*, tick),
			XtRImmediate, (XtPointer) NULL},
		{"cltcpu", "CLTcpu", XtRString, sizeof(String),
			XtOffset(struct _app_res*, cltcpu),
			XtRString, (XtPointer) NULL},
		{"cltmb", "CLTmb", XtRString, sizeof(String),
			XtOffset(struct _app_res*, cltmb),
			XtRString, (XtPointer) NULL},
		{"cltcs", "CLTcs", XtRString, sizeof(String),
			XtOffset(struct _app_res*, cltcs),
			XtRString, (XtPointer) NULL},
		{"clfan1", "CLFan1", XtRString, sizeof(String),
			XtOffset(struct _app_res*, clfan1),
			XtRString, (XtPointer) NULL},
		{"clfan2", "CLFan2", XtRString, sizeof(String),
			XtOffset(struct _app_res*, clfan2),
			XtRString, (XtPointer) NULL},
		{"clvc", "CLVc", XtRString, sizeof(String),
			XtOffset(struct _app_res*, clvc),
			XtRString, (XtPointer) NULL},
		{"cmtcpu", "CMTcpu", XtRString, sizeof(String),
			XtOffset(struct _app_res*, cmtcpu),
			XtRString, (XtPointer) NULL},
		{"cmtmb", "CMTmb", XtRString, sizeof(String),
			XtOffset(struct _app_res*, cmtmb),
			XtRString, (XtPointer) NULL},
		{"cmtcs", "CMTcs", XtRString, sizeof(String),
			XtOffset(struct _app_res*, cmtcs),
			XtRString, (XtPointer) NULL},
		{"cmfan1", "CMFan1", XtRString, sizeof(String),
			XtOffset(struct _app_res*, cmfan1),
			XtRString, (XtPointer) NULL},
		{"cmfan2", "CMFan2", XtRString, sizeof(String),
			XtOffset(struct _app_res*, cmfan2),
			XtRString, (XtPointer) NULL},
		{"cmvc", "CMVc", XtRString, sizeof(String),
			XtOffset(struct _app_res*, cmvc),
			XtRString, (XtPointer) NULL},
		{"fahrn","Fahrn",XtRBoolean,sizeof(Boolean),
			XtOffset(struct _app_res*, fahrn),
			XtRImmediate, (XtPointer) NULL},
		{"label","Label",XtRString,sizeof(String),
			XtOffset(struct _app_res*, label),
			XtRString,(XtPointer) NULL},
		{"labelfont","LabelFont",XtRString,sizeof(String),
			XtOffset(struct _app_res*, labelfont),
			XtRString,(XtPointer) NULL},
		{"labelcolor","LabelColor",XtRString,sizeof(String),
			XtOffset(struct _app_res*, labelcolor),
			XtRString,(XtPointer) NULL},
	};

	static XrmOptionDescRec options[] = {
		{"-font", ".font", XrmoptionSepArg, NULL},
		{"-count", ".count", XrmoptionSepArg, NULL},
		{"-sec", ".sec", XrmoptionSepArg, NULL},
		{"-wsec", ".wsec", XrmoptionSepArg, NULL},
		{"-tmin", ".tmin", XrmoptionSepArg, NULL},
		{"-tmax", ".tmax", XrmoptionSepArg, NULL},
		{"-vmin", ".vmin", XrmoptionSepArg, NULL},
		{"-vmax", ".vmax", XrmoptionSepArg, NULL},
		{"-tick", ".tick", XrmoptionSepArg, NULL},
		{"-cltcpu", ".cltcpu", XrmoptionSepArg, NULL},
		{"-cltmb", ".cltmb", XrmoptionSepArg, NULL},
		{"-cltcs", ".cltcs", XrmoptionSepArg, NULL},
		{"-clfan1", ".clfan1", XrmoptionSepArg, NULL},
		{"-clfan2", ".clfan2", XrmoptionSepArg, NULL},
		{"-clvc", ".clvc", XrmoptionSepArg, NULL},
		{"-cmtcpu", ".cmtcpu", XrmoptionSepArg, NULL},
		{"-cmtmb", ".cmtmb", XrmoptionSepArg, NULL},
		{"-cmtcs", ".cmtcs", XrmoptionSepArg, NULL},
		{"-cmfan1", ".cmfan1", XrmoptionSepArg, NULL},
		{"-cmfan2", ".cmfan2", XrmoptionSepArg, NULL},
		{"-cmvc", ".cmvc", XrmoptionSepArg, NULL},
		{"-fahrn",".fahrn",XrmoptionSepArg,NULL},
		{"-label",".label",XrmoptionSepArg,NULL},
		{"-labelfont",".labelfont",XrmoptionSepArg,NULL},
		{"-labelcolor",".labelcolor",XrmoptionSepArg,NULL},
	};

/*---------- end of static data for X Toolkits ----------*/

void usage(void)
{
	fprintf(stderr,
""RES_NAME" options:\n"
"    -g     ("DEFAULT_GEOMETRY")  <geometry(Toolkit option)>\n"
"    -count       ("DEFAULT_COUNT")  <counts in an interval>\n"
"    -sec         ("DEFAULT_SEC")  <seconds of an interval>\n"
"    -wsec      ("DEFAULT_WSEC")  <total seconds shown>\n"
"    -tmin     ("DEFAULT_TMIN")  <min. temperature>\n"
"    -tmax     ("DEFAULT_TMAX")  <max. temperature>\n"
"    -vmin     ("DEFAULT_VMIN")  <min. voltage>\n"
"    -vmax     ("DEFAULT_VMAX")  <max. voltage>\n"
"    -tick        ("DEFAULT_TICK")  <ticks in ordinate>\n"
"    -cltcpu    ("DEFAULT_CLTCPU")  <color of Temp1>\n"
"    -cltmb    ("DEFAULT_CLTMB")  <color of Temp2>\n"
"    -cltcs    ("DEFAULT_CLTCS")  <color of Temp3>\n"
"    -clfan1   ("DEFAULT_CLFAN1")  <color of Fan1>\n"
"    -clfan2   ("DEFAULT_CLFAN2")  <color of Fan2>\n"
"    -clvc    ("DEFAULT_CLVC")  <color of Vcore>\n"
"    -cmtcpu    ("DEFAULT_CMTCPU")  <comment of Temp1>\n"
"    -cmtmb      ("DEFAULT_CMTMB")  <comment of Temp2>\n"
"    -cmtcs    ("DEFAULT_CMTCS")  <comment of Temp3>\n"
"    -cmfan1   ("DEFAULT_CMFAN1")  <comment of Fan1>\n"
"    -cmfan2   ("DEFAULT_CMFAN2")  <comment of Fan2>\n"
"    -cmvc     ("DEFAULT_CMVC")  <comment of Vcore>\n"
"    -fahrn   ("DEFAULT_FAHRN")  <temp. in Fahrenheit (True|False)>\n"
"    -label       ( )  <for showing label and -labelfont, -labelcolor>\n");
	exit(1);
}

/* Xt Application Context, global */
XtAppContext app_con;
	
int main(int argc, char *argv[])
{
	int i;
	const char *dev = "/dev/sysmon";

	for (i = 1; i < argc; i++)
		if (0 == strcmp("-h", argv[i]) || 0 == strcmp("-help", argv[i]))
			usage();

	if ((fd = open(dev, O_RDONLY)) == -1)
		err(1, "unable to open %s", dev);

	if ((ns = num_sensors()) <= 0)
		errx(1, "cannot determine number of sensors");

	etds = (envsys_tre_data_t *)malloc(ns * sizeof(envsys_tre_data_t));
	if (etds == NULL)
		errx(1, "cannot allocate memory");

	wgt = XtVaAppInitialize(&app_con, RES_NAME, options, XtNumber(options),
				&argc, argv, fallback_resources, NULL);
	XtVaGetApplicationResources(wgt, (caddr_t) &app_resources,
				    resources, XtNumber(resources), NULL);
	XtAppAddActions(app_con, actions, XtNumber(actions));
	XtRealizeWidget(wgt);

	get_res();
	init_dt();

	XtAppAddTimeOut(app_con, ms, (XtTimerCallbackProc) alarm_handler, NULL);
	XtAppMainLoop(app_con);

	return (0);
}

void get_res()
{
	font = app_resources.font;
	if (font == NULL)
		font = DEFAULT_FONT;
	count = app_resources.count;
	if (count <= 0)
		count = atoi(DEFAULT_COUNT);
	sec = app_resources.sec;
	if (sec <= 0)
		sec = atoi(DEFAULT_SEC);
	wsec = app_resources.wsec;
	if (wsec <= 0)
		wsec = atoi(DEFAULT_WSEC);
	tmin = app_resources.tmin;
	if (tmin <= 0.0)
		tmin = (float) atof(DEFAULT_TMIN);
	tmax = app_resources.tmax;
	if (tmax <= 0.0)
		tmax = (float) atof(DEFAULT_TMAX);
	vmin = app_resources.vmin;
	if (vmin <= 0.0)
		vmin = (float) atof(DEFAULT_VMIN);
	vmax = app_resources.vmax;
	if (vmax <= 0.0)
		vmax = (float) atof(DEFAULT_VMAX);
	tick = app_resources.tick;
	if (tick <= 0)
		tick = atoi(DEFAULT_TICK);
	l_color[0] = app_resources.cltcpu;
	if (l_color[0] == NULL)
		l_color[0] = DEFAULT_CLTCPU;
	l_color[1] = app_resources.cltmb;
	if (l_color[1] == NULL)
		l_color[1] = DEFAULT_CLTMB;
	l_color[2] = app_resources.cltcs;
	if (l_color[2] == NULL)
		l_color[2] = DEFAULT_CLTCS;
	l_color[3] = app_resources.clfan1;
	if (l_color[3] == NULL)
		l_color[3] = DEFAULT_CLFAN1;
	l_color[4] = app_resources.clfan2;
	if (l_color[4] == NULL)
		l_color[4] = DEFAULT_CLFAN2;
	l_color[5] = app_resources.clvc;
	if (l_color[5] == NULL)
		l_color[5] = DEFAULT_CLVC;
	c_rdg[0] = app_resources.cmtcpu;
	if (c_rdg[0] == NULL)
		c_rdg[0] = DEFAULT_CMTCPU;
	c_rdg[1] = app_resources.cmtmb;
	if (c_rdg[1] == NULL)
		c_rdg[1] = DEFAULT_CMTMB;
	c_rdg[2] = app_resources.cmtcs;
	if (c_rdg[2] == NULL)
		c_rdg[2] = DEFAULT_CMTCS;
	c_rdg[3] = app_resources.cmfan1;
	if (c_rdg[3] == NULL)
		c_rdg[3] = DEFAULT_CMFAN1;
	c_rdg[4] = app_resources.cmfan2;
	if (c_rdg[4] == NULL)
		c_rdg[4] = DEFAULT_CMFAN2;
	c_rdg[5] = app_resources.cmvc;
	if (c_rdg[5] == NULL)
		c_rdg[5] = DEFAULT_CMVC;
	if (app_resources.fahrn) {
		fahrn_flag = 1;
		if (tmin == (float) atof(DEFAULT_TMIN) &&
		    tmax == (float) atof(DEFAULT_TMAX)) {
			tmin = (float) atof(DEFAULT_TMINF);
			tmax = (float) atof(DEFAULT_TMAXF);
		}
	}
	label = app_resources.label;
	lb_font = app_resources.labelfont;
	lb_color = app_resources.labelcolor;
	if (lb_color == NULL)
		lb_color = DEFAULT_LBCOLOR;
}

void quit_proc(void)
{
	exit(1);
}

void repaint_proc(void)
{
	int wwd, hht;
	int i, n;
	ring_d *p;

	getWH(&wwd, &hht);
	if (wwd != width) {
		width = wwd;
		x_cm = width - XTextWidth(fontstr, cvmin, strlen(cvmin)) - 1;
		sscl = (float) width / (float) range;
		calc_position();
	}

	if (hht != height) {
		height = hht;
		calc_scale();
	}

	XClearWindow(disp, win);

	if(*label != NULL)
		XDrawString(disp, win, gclb, 2, h_lb - 2, label, strlen(label));

	for (i = 0; i < nd; i++) {
		XDrawString(disp, win, gcl[i], x_rdg[i], y_rdg,
			    c_rdg[i], strlen(c_rdg[i]));
		XDrawString(disp, win, gcl[i], x_rdv[i], y_rdv,
			    c_rdv[i], strlen(c_rdv[i]));
	}

	XDrawString(disp, win, gct, 0, height, ctmin, strlen(ctmin));
	XDrawString(disp, win, gct, 0, y_cm, ctmax, strlen(ctmax));
	XDrawString(disp, win, gct, x_cm, height, cvmin, strlen(cvmin));
	XDrawString(disp, win, gct, x_cm, y_cm, cvmax, strlen(cvmax));

	for (i = 1; i <= tick + 1; i++) {
		n = height - (int) ((float) i * htck + 0.5);
		XDrawLine(disp, win, gct, 0, n, width, n);
	}

	for (i = nd - 1; i >= 0; i--) {
		for (n = 0, p = rdp[i]; n < npoints; n++) {
			(points + n)->x = (short) ((float) n * sscl + 0.5);
			(points + n)->y = height -
			    (short) ((p->val - orign[i]) * scale[i] + 0.5);
			p = p->next;
		}

		if (scale[i])
			XDrawLines(disp, win, gcl[i], points, npoints,
				   CoordModeOrigin);
	}

	XFlush(disp);
}

void getWH(int *width, int *height)
{
	Dimension wd, ht;

	XtVaGetValues(wgt, XtNwidth, &wd, XtNheight, &ht, NULL);
	*width = (int) wd;
	*height = (int) ht;
}

int ColorPix(Display *display, char *color, unsigned long *cpix)
{
	Colormap cmap;
	XColor c0, c1;

	if (color == NULL)
		return (1);

	cmap = DefaultColormap(display, 0);
	if (XAllocNamedColor(disp, cmap, color, &c1, &c0)) {
		*cpix = c1.pixel;
		return (0);
	} else
		return (1);
}

void init_dt(void)
{
	ring_d *p;
	int n, i;
	
	if (wsec < 10 * sec)
		errx(1, "wsec(%d) is too small w.r.t sec(%d)!", wsec, sec);

	if (tmax < tmin)
		errx(1, "tmin(%f) > tmax(%f), not allowed!", tmin, tmax);

	if (vmax < vmin)
		errx(1, "vmin(%f) > vmax(%f), not allowed!", vmin, vmax);

	if (fill_sensors() == -1)
		errx(1, "cannot enumerate sensors");

	get_values();
	disp = XtDisplay(wgt);
	win = XtWindow(wgt);

	if ((fontstr = XLoadQueryFont(disp, font)) == NULL)
		errx(1, "Can't find font: %s\n", font);

	ColorPix(disp, DEFAULT_CLTCPU, &(d_cpix[0]));
	ColorPix(disp, DEFAULT_CLTMB, &(d_cpix[1]));
	ColorPix(disp, DEFAULT_CLTCS, &(d_cpix[2]));
	ColorPix(disp, DEFAULT_CLFAN1, &(d_cpix[3]));
	ColorPix(disp, DEFAULT_CLFAN2, &(d_cpix[4]));
	ColorPix(disp, DEFAULT_CLVC, &(d_cpix[5]));
	gct = XCreateGC(disp, win, 0, 0);
	XSetFont(disp, gct, fontstr->fid);

	for (i = 0; i < nd; i++) {
		if (ColorPix(disp, l_color[i], &(cpix[i])))
			cpix[i] = d_cpix[i];

		gcl[i] = XCreateGC(disp, win, 0, 0);
		XSetLineAttributes(disp, gcl[i], 2, LineSolid, CapRound,
				   JoinRound);
		XSetForeground(disp, gcl[i], cpix[i]);
		XSetFont(disp, gcl[i], fontstr->fid);
		c_rdv[i] = (char *) malloc(C_LBL);
		sprintf(c_rdv[i], c_rdp[i], cur_val[i]);
		cg_width[i] = XTextWidth(fontstr, c_rdg[i], strlen(c_rdg[i]));
		cv_width[i] = XTextWidth(fontstr, c_rdv[i], strlen(c_rdv[i]));
	}

	if(*label != NULL) {
		if ((lb_fontstr = XLoadQueryFont(disp, lb_font)) == NULL)
			errx(1, "Can't find font for label: %s\n", font);

		ColorPix(disp, DEFAULT_LBCOLOR, &d_cpixlb);
		if (ColorPix(disp, lb_color, &cpixlb))
			cpixlb = d_cpixlb;

		gclb = XCreateGC(disp, win, 0, 0);
		XSetFont(disp, gclb, lb_fontstr->fid);
		XSetForeground(disp, gclb, cpixlb);
	}

	sprintf(ctmin, "%2.0f", tmin);
	sprintf(ctmax, "%2.0f", tmax);
	sprintf(cvmin, "%3.1f", vmin);
	sprintf(cvmax, "%3.1f", vmax);

	range = wsec / sec;
	points = (XPoint *) malloc(sizeof(short) * 2 * (range + 1));

	for (i = 0; i < nd; i++) {
		rdp[i] = p = (ring_d *) malloc(sizeof(ring_d));	
		rdpw[i] = p;
		for (n = 1; n < (range + 1); n++) {
			p->next = (ring_d *) malloc(sizeof(ring_d));	
			p = p->next;
		}

		p->next = rdp[i];
	}

	fmean = (float *) malloc(sizeof(float) * nd * count);

	getWH(&width, &height);
	sscl = (float) width / (float) range;
	orign[0] = tmin;
	orign[1] = tmin;
	orign[2] = tmin;
	orign[5] = vmin;
	x_rdg[0] = 0;
	x_rdv[0] = 0;

	calc_position();

	y_rdg = fontstr->max_bounds.ascent - 1;
	y_rdv = 2 * y_rdg;

	if(*label != NULL) {
		h_lb = lb_fontstr->max_bounds.ascent + 1;
		y_rdg += h_lb;
		y_rdv += h_lb;
	}

	h_cm = 2 * fontstr->max_bounds.ascent;
	y_cm = h_cm + y_rdg;
	x_cm = width - XTextWidth(fontstr, cvmin, strlen(cvmin));
	calc_scale();

	ms = 1000 * sec / count;
}

void alarm_handler(void)
{
	float d, *p;
	int i, n;

	get_values();
	if (fill_sensors() == -1)
		errx(1, "cannot enumerate sensors");

	if (cur_val[0] >= tmax)
		XBell(XtDisplay(wgt), 0);

	draw_values();

	p = fmean + counter;
	for (i = 0; i < nd; i++)
		*(p + i * count) = cur_val[i];

	counter++;
	if (counter == count) {
		if (npoints <= range)
			npoints++;
		else
			for (i = 0; i < nd; i++)
				rdp[i] = rdp[i]->next;

		counter = 0;
		p = fmean;
		for (i = 0; i < nd; i++) {
			for (n = 0, d = 0.0; n < count; n++, p++)
				d += *p;

			rdpw[i]->val = d / (float) count;
			rdpw[i] = rdpw[i]->next;
		}

		repaint_proc();
	}

	XtAppAddTimeOut(app_con, ms, (XtTimerCallbackProc) alarm_handler, NULL);
}

void draw_values(void)
{
	int i;

	XClearArea(disp, win, 0, y_rdg , 0, y_rdg - h_lb, False);
	for (i = 0; i < nd; i++) {
		sprintf(c_rdv[i], c_rdp[i], cur_val[i]);
		XDrawString(disp, win, gcl[i], x_rdv[i], y_rdv,
			    c_rdv[i], strlen(c_rdv[i]));
	}

	XFlush(disp);
}

void calc_position(void)
{
	int i, cg_r, cv_r;

	cg_r = width - (cg_width[0] + cg_width[nd - 1]) / 2;
	cv_r = width - (cv_width[0] + cv_width[nd - 1]) / 2;
	for (i = 1; i <= nd - 1; i++) {
		x_rdg[i] =
		    cg_width[0] / 2 + cg_r * i / (nd - 1) - cg_width[i] / 2;
		x_rdv[i] =
		    cv_width[0] / 2 + cv_r * i / (nd - 1) - cv_width[i] / 2;
	}
}

void calc_scale(void)
{
	float tscl, vscl;

	tscl = (float) (height - h_lb - h_cm) / (tmax - tmin);
	vscl = (float) (height - h_lb - h_cm) / (vmax - vmin);
	htck = (float) (height - h_lb - h_cm) / (float) (tick + 1);
	scale[0] = tscl;
	scale[1] = tscl;
	scale[2] = tscl;
	scale[3] = 0;
	scale[4] = 0;
	scale[5] = vscl;
}

int num_sensors(void)
{
	int num = 0, valid = 1;
	envsys_tre_data_t etd;
	etd.sensor = 0;

	while (valid) {
		if (ioctl(fd, ENVSYS_GTREDATA, &etd) == -1)
			errx(1, "cannot enumerate sensors");

		valid = etd.validflags & ENVSYS_FVALID;
		if (valid)
			++num;

		++etd.sensor;
	}

	return (num);
}

int fill_sensors(void)
{
	int i;

	for (i = 0; i < ns; ++i) {
		etds[i].sensor = i;
		if (ioctl(fd, ENVSYS_GTREDATA, &etds[i]) == -1)
			return (-1);
	}

	return (0);
}

void get_values(void)
{
	int i, j = 0, k = 0, l = 0;

	for (i = 0; i < ns; ++i) {
		if ((etds[i].validflags & ENVSYS_FCURVALID) == 0)
			continue;

		switch (etds[i].units) {
		case ENVSYS_STEMP:
			cur_val[j] = (etds[i].cur.data_us / 1000000.0) - 273.15;
			if (fahrn_flag)
				cur_val[j] = (9.0 / 5.0) * cur_val[j] + 32.0;

			++j;
			break;
		case ENVSYS_SFANRPM:
			if (k < 2)
				cur_val[k + 3] = etds[i].cur.data_us;

			++k;
			break;
		default:
			if (l < 1)
				cur_val[5] = etds[i].cur.data_s / 1000000.0;

			++l;
			break;
		}
	}
}
