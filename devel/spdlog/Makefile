# $NetBSD: Makefile,v 1.2 2020/06/05 11:22:44 ryoon Exp $

DISTNAME=		spdlog-1.6.1
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
