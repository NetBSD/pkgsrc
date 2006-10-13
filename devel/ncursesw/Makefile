# $NetBSD: Makefile,v 1.1 2006/10/13 18:07:49 tron Exp $

.include "../../devel/ncurses/Makefile.common"

PKGNAME=	${DISTNAME:S/ncurses/ncursesw/}
COMMENT=	Wide character CRT screen handling and optimization package

PATCHDIR=	${.CURDIR}/../../devel/ncurses/patches
DISTINFO_FILE=	${.CURDIR}/../../devel/ncurses/distinfo

CONFIGURE_ARGS+=	--enable-widec

BUILD_TARGET=	libs

do-install:
	for LIB in form menu ncurses++ ncurses panel; do	\
		${LIBTOOL} --mode=install ${INSTALL_PROGRAM}	\
		    ${WRKSRC}/lib/lib$${LIB}w.la ${PREFIX}/lib;	\
	done

BUILDLINK_API_DEPENDS.ncurses+=	ncurses-${NC_VERS}{,nb*}
BUILDLINK_ABI_DEPENDS.ncurses+=	ncurses-${NC_VERS}{,nb*}
USE_NCURSES=			yes

.include "../../devel/ncurses/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
