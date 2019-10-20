# $NetBSD: Makefile,v 1.1 2019/10/20 15:25:18 nia Exp $

DISTNAME=	faba-icon-theme-4.3
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=snwh/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://snwh.org/moka
COMMENT=	Modern icon theme with Tango influences
LICENSE=	cc-by-sa-v4.0

USE_LANGUAGES=	# none
ICON_THEMES=	yes

REPLACE_PYTHON+=	meson/post_install.py

# Requires Python 3
PYTHON_VERSIONS_INCOMPATIBLE=	27
PYTHON_FOR_BUILD_ONLY=		tool

# Save some time...
CHECK_WRKREF_SKIP+=		share/icons/Faba/*/*/*.png
CHECK_INTERPRETER_SKIP+=	share/icons/Faba/*/*/*.png

.include "../../devel/meson/build.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
