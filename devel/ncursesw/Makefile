# $NetBSD: Makefile,v 1.14 2017/08/08 18:38:21 spz Exp $

PKGREVISION= 3
.include "../../devel/ncurses/Makefile.common"

PKGNAME=	${DISTNAME:S/ncurses/ncursesw/}
COMMENT=	Wide character CRT screen handling and optimization package

PATCHDIR=	${.CURDIR}/../../devel/ncurses/patches
DISTINFO_FILE=	${.CURDIR}/../../devel/ncurses/distinfo

CONFIGURE_ARGS+=	--enable-widec
CONFIGURE_ARGS+=	--includedir=${PREFIX}/include/ncursesw

INSTALLATION_DIRS+=	include/ncursesw
INSTALLATION_DIRS+=	bin
INSTALLATION_DIRS+=	lib

BUILD_TARGET=	libs

SUBST_CLASSES+=		includes
SUBST_MESSAGE.includes=	Fixing include paths for ncurses headers.
SUBST_STAGE.includes=	post-build
SUBST_FILES.includes=	include/curses.h
SUBST_SED.includes=	-e 's,<ncurses_dll\.h>,<ncurses/ncurses_dll\.h>,'
SUBST_SED.includes+=	-e 's,<unctrl\.h>,<ncurses/unctrl\.h>,'

do-install:
	cd ${WRKSRC}/include &&	\
	${MAKE_ENV} ${MAKE_PROGRAM} ${INSTALL_MAKE_FLAGS} install
	${INSTALL_SCRIPT} ${WRKSRC}/misc/ncurses-config ${DESTDIR}${PREFIX}/bin/ncursesw${NC_VERS:R}-config
	for LIB in gnuform gnumenu ncurses++ ncurses gnupanel; do	\
		${LIBTOOL} --mode=install ${INSTALL_PROGRAM}	\
		    ${WRKSRC}/lib/lib$${LIB}w.la ${DESTDIR}${PREFIX}/lib;	\
	done

BUILDLINK_API_DEPENDS.ncurses+=	ncurses-${NC_VERS}{,nb*}
BUILDLINK_ABI_DEPENDS.ncurses+=	ncurses-${NC_VERS}{,nb*}
USE_NCURSES=			yes

.include "../../devel/ncurses/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
