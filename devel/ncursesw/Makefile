# $NetBSD: Makefile,v 1.2 2007/09/13 23:13:47 wiz Exp $

.include "../../devel/ncurses/Makefile.common"

PKGNAME=	${DISTNAME:S/ncurses/ncursesw/}
PKGREVISION=	1
COMMENT=	Wide character CRT screen handling and optimization package

PATCHDIR=	${.CURDIR}/../../devel/ncurses/patches
DISTINFO_FILE=	${.CURDIR}/../../devel/ncurses/distinfo

CONFIGURE_ARGS+=	--enable-widec

INSTALLATION_DIRS+=	include/ncursesw

BUILD_TARGET=	libs

do-install:
	${INSTALL_DATA} ${WRKSRC}/include/curses.h ${PREFIX}/include/ncursesw/ncurses.h
	for LIB in form menu ncurses++ ncurses panel; do	\
		${LIBTOOL} --mode=install ${INSTALL_PROGRAM}	\
		    ${WRKSRC}/lib/lib$${LIB}w.la ${PREFIX}/lib;	\
	done

BUILDLINK_API_DEPENDS.ncurses+=	ncurses-${NC_VERS}{,nb*}
BUILDLINK_ABI_DEPENDS.ncurses+=	ncurses-${NC_VERS}{,nb*}
USE_NCURSES=			yes

.include "../../devel/ncurses/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
