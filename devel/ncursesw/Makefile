# $NetBSD: Makefile,v 1.6 2010/01/11 10:38:16 tron Exp $

.include "../../devel/ncurses/Makefile.common"

PKGNAME=	${DISTNAME:S/ncurses/ncursesw/}
COMMENT=	Wide character CRT screen handling and optimization package

PATCHDIR=	${.CURDIR}/../../devel/ncurses/patches
DISTINFO_FILE=	${.CURDIR}/../../devel/ncurses/distinfo

CONFIGURE_ARGS+=	--enable-widec

INSTALLATION_DIRS+=	include/ncursesw
INSTALLATION_DIRS+=	lib

BUILD_TARGET=	libs

.if ${OPSYS} == "SunOS"
CXXFLAGS+=	-D_XPG5
.endif

do-install:
	${INSTALL_DATA} ${WRKSRC}/include/curses.h ${DESTDIR}${PREFIX}/include/ncursesw/ncurses.h
	for LIB in form menu ncurses++ ncurses panel; do	\
		${LIBTOOL} --mode=install ${INSTALL_PROGRAM}	\
		    ${WRKSRC}/lib/lib$${LIB}w.la ${DESTDIR}${PREFIX}/lib;	\
	done

BUILDLINK_API_DEPENDS.ncurses+=	ncurses-${NC_VERS}{,nb*}
BUILDLINK_ABI_DEPENDS.ncurses+=	ncurses-${NC_VERS}{,nb*}
USE_NCURSES=			yes

.include "../../devel/ncurses/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
