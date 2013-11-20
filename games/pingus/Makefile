# $NetBSD: Makefile,v 1.15 2013/11/20 20:04:37 adam Exp $

DISTNAME=	pingus-0.7.3
PKGREVISION=	10
CATEGORIES=	games
MASTER_SITES=	http://pingus.seul.org/files/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://pingus.seul.org/
COMMENT=	Lemmings(TM) Clone

BUILD_DEPENDS+=		scons>=0.96:../../devel/scons
USE_LANGUAGES+=		c c++

SUBST_CLASSES+=			fix-prefix
SUBST_STAGE.fix-prefix=		post-patch
SUBST_MESSAGE.fix-prefix=	Fixing buildlink prefix
SUBST_FILES.fix-prefix=		SConstruct
SUBST_SED.fix-prefix=		-e 's,BUILDLINK_DIR,${BUILDLINK_DIR},'

MAKE_JOBS?=	1

.include "../../mk/compiler.mk"
.if !empty(PKGSRC_COMPILER:Mclang)
SCONS_CXX=	${CXX} -std=c++11
.else
SCONS_CXX=	${CXX}
.endif

MAKE_ENV+=	CPPPATH=${BUILDLINK_DIR}/include LIBPATH=${BUILDLINK_DIR}/lib

do-configure:
	cd ${WRKSRC} && \
	${PKGSRC_SETENV} ${MAKE_ENV} scons configure CXX=${SCONS_CXX:Q}

do-build:
	cd ${WRKSRC} && \
	${PKGSRC_SETENV} ${MAKE_ENV} scons ${_MAKE_JOBS}

do-install:
	cd ${WRKSRC} && ./install.sh ${DESTDIR}${PREFIX}

.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../graphics/SDL_image/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
