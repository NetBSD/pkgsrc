# $NetBSD: Makefile,v 1.30 2000/06/01 11:23:23 rh Exp $

DISTNAME=		ncurses-5.0
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GNU:=ncurses/} \
			ftp://ftp.clark.net/pub/dickey/ncurses/

MAINTAINER=		jlam@netbsd.org
HOMEPAGE=		http://www.clark.net/pub/dickey/ncurses/ncurses.html

GNU_CONFIGURE=		yes
USE_PKGLIBTOOL=		yes
CONFIGURE_ARGS+=	--with-normal --enable-bsdpad \
			--without-shared --without-debug --without-profile \
			--without-gpm --without-ada \
			--with-manpage-format=normal
MAKE_ENV+=		NCURSES_MAJOR="${NCURSES_MAJOR}" \
			NCURSES_MINOR="${NCURSES_MINOR}"

# Define these here so they can be conveniently changed when ncurses
# is integrated into the NetBSD source tree.
#
NCURSES_MAJOR=		5
NCURSES_MINOR=		0

# The following installed headers directly reference <curses.h> and must be
# altered to reference <ncurses.h> instead.
#
CURSES_INCLUDES=	c++/cursesw.h form/form.h include/unctrl.h \
			menu/menu.h panel/panel.h
CURSES_MAN_WITH_TABLES=	captoinfo.1m curs_addch.3x curs_attr.3x \
			curs_getch.3x curs_inch.3x curs_mouse.3x \
			form.3x infocmp.1m menu.3x ncurses.3x
#			terminfo.5 is handled by patch-ac
SED_NCURSES=		'/\#[ 	]*include/s/curses.h/ncurses.h/'

post-configure:
	cd ${WRKSRC};							\
	${LN} -sf curses.h include/ncurses.h;				\
	for file in ${CURSES_INCLUDES}; do				\
		${SED} -e ${SED_NCURSES} <$${file} >$${file}.tmp;	\
		${MV} -f $${file}.tmp $${file};				\
	done
	cd ${WRKSRC}/man;						\
	${RM} -f clear.1 tput.1 tset.1;					\
	for file in ${CURSES_MAN_WITH_TABLES}; do			\
		tbl $${file} > $${file}.notbl;				\
		${MV} $${file}.notbl $${file};				\
	done;								\
	for file in *.1m; do						\
		${SED} -e ${SED_NCURSES} <$${file} >`basename $${file} .1m`.1; \
		${RM} -f $${file};					\
	done;								\
	for file in *.3x; do						\
		${SED} -e ${SED_NCURSES} <$${file} >`basename $${file} .3x`.3; \
		${RM} -f $${file};					\
	done

post-install:
	${INSTALL_DATA} ${WRKSRC}/c++/demo.cc \
		${PREFIX}/share/examples/ncurses++demo.cc

.include "../../mk/bsd.pkg.mk"
