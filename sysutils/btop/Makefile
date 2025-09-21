# $NetBSD: Makefile,v 1.5 2025/09/21 17:58:05 wiz Exp $

DISTNAME=	btop-1.4.5
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=aristocratos/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/aristocratos/btop
COMMENT=	Colorful TTY resource monitor
LICENSE=	apache-2.0

TOOL_DEPENDS+=	lowdown-[0-9]*:../../textproc/lowdown

USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake

USE_CXX_FEATURES+=	c++20

INSTALLATION_DIRS=	${PKGMANDIR}/man1

CXXFLAGS+=	-DNDEBUG
MAKE_ENV+=	STRIP=true VERBOSE=true

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../mk/atomic64.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
