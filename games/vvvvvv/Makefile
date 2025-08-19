# $NetBSD: Makefile,v 1.15 2025/08/19 12:02:16 wiz Exp $

DISTNAME=	VVVVVV-0.0.0.20200110
PKGNAME=	${DISTNAME:tl}
PKGREVISION=	9
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=TerryCavanagh/}
GITHUB_PROJECT=	VVVVVV
GITHUB_TAG=	9e5e9f3e670a0cc48475a20486b0630e83ae14b4

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/TerryCavanagh/VVVVVV
COMMENT=	2D puzzle platform video game with gravity reversal
LICENSE=	vvvvvv-license

CONFLICTS+=	vvvvvvv-[0-9]*
SUPERSEDES+=	vvvvvvv-[0-9]*

WRKSRC=		${WRKDIR}/VVVVVV-${GITHUB_TAG}/desktop_version
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

INSTALLATION_DIRS+=	bin

CMAKE_CONFIGURE_ARGS+=	-DCMAKE_POLICY_VERSION_MINIMUM=3.5

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${CMAKE_BUILD_DIR}/vvvvvv* ${DESTDIR}${PREFIX}/bin/vvvvvv

.include "../../devel/cmake/build.mk"
.include "../../audio/SDL2_mixer/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../devel/physfs/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
