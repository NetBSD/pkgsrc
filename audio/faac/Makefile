# $NetBSD: Makefile,v 1.21 2026/09/08 15:39:45 kikadf Exp $

DISTNAME=	faac-1.50
PKGREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_GITHUB:=knik0/}
GITHUB_TAG=	${DISTNAME}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/knik0/faac
COMMENT=	AAC audio encoder
LICENSE=	gnu-lgpl-v2

USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=	libfaac/faac.pc.in

.include "../../devel/meson/build.mk"
.include "../../mk/bsd.pkg.mk"
