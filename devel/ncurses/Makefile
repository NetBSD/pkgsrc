# New packages collection makefile for:	ncurses
# Version required:     		1.9.9g
# Date created:				Tue Oct 28 00:12:41 CET 1997
# Whom:					Hubert Feyrer (hubertf@netbsd.org)
#
# $NetBSD: Makefile,v 1.12 1998/03/16 11:06:07 frueauf Exp $

DISTNAME=	ncurses-1.9.9g
CATEGORIES=	devel
# XXX this should be moved to ftp.netcom.com:/pub/zm/zmbenhal/ncurses/
# XXX once upgraded to the latest version - hubertf
MASTER_SITES=	ftp://ftp.fu-berlin.de/unix/gnu/ncurses/

MAINTAINER=	hubertf@netbsd.org

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+= --with-normal --with-shared --enable-bsdpad
WRKSRC=		${WRKDIR}/ncurses_1.9.9g

#MANCOMPRESSED=	yes
MAN1=		captoinfo.1 infocmp.1 tic.1 toe.1
MAN3=		curs_addch.3 curs_addchstr.3 curs_addstr.3 curs_attr.3 \
		curs_beep.3 curs_bkgd.3 curs_border.3 curs_clear.3 \
		curs_color.3 curs_delch.3 curs_deleteln.3 curs_getch.3 \
		curs_getstr.3 curs_getyx.3 curs_inch.3 curs_inchstr.3 \
		curs_initscr.3 curs_inopts.3 curs_insch.3 \
		curs_insstr.3 curs_instr.3 curs_kernel.3 curs_mouse.3 \
		curs_move.3 curs_outopts.3 curs_overlay.3 curs_pad.3 \
		curs_printw.3 curs_refresh.3 \
		curs_scanw.3 curs_scr_dmp.3 curs_scroll.3 curs_slk.3 \
		curs_termattrs.3 curs_termcap.3 curs_terminfo.3 \
		curs_touch.3 curs_util.3 curs_window.3 form.3 \
		form_cursor.3 form_data.3 form_driver.3 menu.3 \
		form_field.3 form_field_attributes.3 \
		form_field_buffer.3 form_field_info.3 \
		form_field_just.3 form_field_new.3 form_field_opts.3 \
		form_field_userptr.3 form_field_validation.3 \
		form_fieldtype.3 form_hook.3 form_new.3 \
		form_new_page.3 form_opts.3 form_page.3 form_post.3 \
		form_userptr.3 form_win.3 menu_attribs.3 menu_cursor.3 \
		menu_driver.3 menu_format.3 menu_hook.3 menu_items.3 \
		menu_mark.3 menu_new.3 menu_opts.3 menu_pattern.3 \
		menu_post.3 menu_userptr.3 menu_win.3 mitem_current.3 \
		mitem_name.3 mitem_new.3 mitem_opts.3 mitem_userptr.3 \
		mitem_value.3 mitem_visible.3 ncurses.3 panel.3 \
		wresize.3 curs_print.3 form_requestname.3 resizeterm.3 \
		menu_requestname.3 menu_spacing.3
MAN5=		terminfo.5 term.5
MAN7=		term.7

post-patch:
	( cd ${WRKSRC}/man ; ${RM} -f tput.1 tset.1 clear.1 )
	( cd ${WRKSRC}/man ; for i in *.1m ; do \
	  ${SED} -e '/#include/s/curses.h/ncurses.h/' <$$i >`basename $$i .1m`.1 ; \
	  ${RM} -f $$i ; done )
	( cd ${WRKSRC}/man ; for i in *.3x ; do \
	  ${SED} -e '/#include/s/curses.h/ncurses.h/' <$$i >`basename $$i .3x`.3 ; \
	  ${RM} -f $$i ; done )

post-install:
	${MV} ${PREFIX}/include/curses.h ${PREFIX}/include/ncurses.h
	${RM} -f ${PREFIX}/lib/libcurses.a
	( cd ${PREFIX}/include ; for i in form.h menu.h panel.h ; do \
	  ${SED} '/#include/s|curses.h|ncurses.h|g' $$i >$$i.BAK ; \
	  ${MV} $$i.BAK $$i ; done )
	${LDCONFIG} || ${TRUE}

.include <bsd.port.mk>
