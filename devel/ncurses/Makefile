# $NetBSD: Makefile,v 1.40 2002/09/01 18:36:35 tron Exp $

DISTNAME=		ncurses-${NC_VERS}
NC_VERS=		5.2
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GNU:=ncurses/} \
			ftp://dickey.his.com/ncurses/ \
			ftp://dickey.his.com/ncurses/${NC_VERS}/

MAINTAINER=		jlam@netbsd.org
HOMEPAGE=		http://dickey.his.com/ncurses/ncurses.html
COMMENT=		CRT screen handling and optimization package

USE_LIBTOOL=		YES
USE_BUILDLINK2=		YES

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--with-libtool
CONFIGURE_ARGS+=	--enable-bsdpad
CONFIGURE_ARGS+=	--with-cxx-binding
CONFIGURE_ARGS+=	--without-ada
CONFIGURE_ARGS+=	--without-curses-h
CONFIGURE_ARGS+=	--without-gpm
CONFIGURE_ARGS+=	--with-manpage-format=normal
CONFIGURE_ARGS+=	--with-manpage-tbl

.include "../../mk/bsd.prefs.mk"

.if (${OPSYS} == SunOS)
PLIST_SUBST+=	NOT_SUNOS="@comment " TERMINFODIR=share/lib/terminfo

TERMINFO_SRC=	${WRKSRC}/misc/terminfo.src
.else
PLIST_SUBST+=	NOT_SUNOS= TERMINFODIR=share/terminfo
.endif

# Remove these manpages from the distribution so they won't get installed
CURSES_NO_MAN=		clear.1 tput.1 tset.1

post-configure:
	cd ${WRKSRC}/man;					\
	${RM} -f ${CURSES_NO_MAN};				\
	for file in *.1m; do					\
		${MV} -f $${file} `basename $${file} .1m`.1; 	\
	done;							\
	for file in *.3x; do					\
		${MV} -f $${file} `basename $${file} .3x`.3; 	\
	done
.if (${OPSYS} == SunOS)
	${MV} ${TERMINFO_SRC} ${TERMINFO_SRC}.old
	${SED} -e "/^screen|/,/^$$/d"  -e "/^screen-w|/,/^$$/d" \
	   <${TERMINFO_SRC}.old >${TERMINFO_SRC}
.endif

post-install:
	${INSTALL_DATA} ${WRKSRC}/c++/demo.cc \
		${PREFIX}/share/examples/ncurses++demo.cc

.include "../../mk/bsd.pkg.mk"
