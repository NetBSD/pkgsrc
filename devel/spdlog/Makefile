# $NetBSD: Makefile,v 1.5 2021/01/04 12:03:24 wiz Exp $

DISTNAME=		spdlog-1.8.2
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GITHUB:=gabime/}
GITHUB_PROJECT=		spdlog
GITHUB_TAG=		v${PKGVERSION_NOREV}

MAINTAINER=		ryoon@NetBSD.org
HOMEPAGE=		https://github.com/gabime/spdlog
COMMENT=		Fast C++ logging library
LICENSE=		mit

USE_LANGUAGES=		c c++
USE_TOOLS+=		pkg-config
USE_CMAKE=		yes

PKGCONFIG_OVERRIDE+=		cmake/spdlog.pc.in

.include "../../lang/python/tool.mk"
.include "../../mk/bsd.pkg.mk"
