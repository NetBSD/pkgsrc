# $NetBSD: Makefile,v 1.1 2023/05/03 17:43:00 nikita Exp $

PREMAKE5_VERSION=	5.0.0-beta2
DISTNAME=		premake-${PREMAKE5_VERSION}-src
PKGNAME=		premake5-${PREMAKE5_VERSION:S/-beta2/.b2/}
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GITHUB:=premake/}
GITHUB_PROJECT=		premake-core
GITHUB_RELEASE=		v${PREMAKE5_VERSION}
EXTRACT_SUFX=		.zip

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://premake.github.io/
COMMENT=		Build script generator
LICENSE=		modified-bsd

USE_TOOLS+=		gmake

BUILDLINK_TRANSFORM+=	opt:-ldl:${BUILDLINK_LDADD.dl:Q}

BUILD_DIRS+=		build/gmake2.unix

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/release/premake5 \
		${DESTDIR}${PREFIX}/bin/

.include "../../devel/libuuid/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
