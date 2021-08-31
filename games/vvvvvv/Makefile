# $NetBSD: Makefile,v 1.5 2021/08/31 07:39:00 nia Exp $

DISTNAME=	VVVVVV-0.0.0.20200110
PKGNAME=	${DISTNAME:tl}
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
USE_CMAKE=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

INSTALLATION_DIRS+=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/vvvvvv* ${DESTDIR}${PREFIX}/bin/vvvvvv

.include "../../audio/SDL2_mixer/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../devel/physfs/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
