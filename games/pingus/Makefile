# $NetBSD: Makefile,v 1.4 2012/01/28 11:00:55 wiz Exp $

DISTNAME=	pingus-0.7.3
PKGREVISION=	3
CATEGORIES=	games
MASTER_SITES=	http://pingus.seul.org/files/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://pingus.seul.org/
COMMENT=	Lemmings(TM) Clone

PKG_DESTDIR_SUPPORT=	user-destdir

BUILD_DEPENDS+=		scons>=0.96:../../devel/scons
USE_LANGUAGES+=		c++

SUBST_CLASSES+=			fix-prefix
SUBST_STAGE.fix-prefix=		post-patch
SUBST_MESSAGE.fix-prefix=	Fixing buildlink prefix
SUBST_FILES.fix-prefix=		SConstruct
SUBST_SED.fix-prefix=		-e 's,BUILDLINK_DIR,${BUILDLINK_DIR},'

MAKE_JOBS?=	1

do-build:
	cd ${WRKSRC} && \
	CPPPATH=${BUILDLINK_DIR}/include LIBPATH=${BUILDLINK_DIR}/lib scons -j ${MAKE_JOBS}

do-install:
	cd ${WRKSRC} && ./install.sh ${DESTDIR}${PREFIX}

.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../graphics/SDL_image/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
