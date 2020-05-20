# $NetBSD: Makefile,v 1.26 2020/05/20 06:09:09 rillig Exp $

DISTNAME=	xevilsrc2.02r2
PKGNAME=	xevil-2.02
PKGREVISION=	2
CATEGORIES=	games x11
#MASTER_SITES=	http://www.xevil.com/download/stable/
EXTRACT_SUFX=	.zip

MAINTAINER=	snj@pobox.com
#HOMEPAGE=	http://www.xevil.com/
COMMENT=	Side scrolling, bloody action game

MAKE_JOBS_SAFE=		no

MAKE_FILE=	makefile

BUILD_TARGET=	pkgsrc
WRKSRC=		${WRKDIR}

MAKE_ENV+=	HOSTTYPE="pkgsrc"

USE_LANGUAGES=	c++03

# draw.cpp: In member function 'void World::draw_square(Drawable, Xvars&, int, const Loc&, int, int, Boolean)':
# draw.cpp:47:63: error: array subscript has type 'char' [-Werror=char-subscripts]
#    int blockNum = themes[themeIndex].blockIndices[map[l.r][l.c]];
#                                                                ^
# Maybe fix this later.
BUILDLINK_TRANSFORM+=	rm:-Werror=char-subscripts

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/x11/PKGSRC/xevil ${DESTDIR}${PREFIX}/bin/xevil
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/xevil
	${INSTALL_DATA} ${WRKSRC}/instructions/* ${DESTDIR}${PREFIX}/share/doc/xevil

SUBST_CLASSES+=		uname
SUBST_STAGE.uname=	pre-configure
SUBST_FILES.uname=	cmn/utils.cpp
SUBST_VARS.uname=	UNAME

.include "../../x11/libXpm/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
