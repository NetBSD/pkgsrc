# $NetBSD: Makefile,v 1.1 2019/10/20 15:27:12 nia Exp $

DISTNAME=	moka-icon-theme-5.4.0
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=snwh/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://snwh.org/moka
COMMENT=	Simple and bright icon theme
LICENSE=	cc-by-sa-v4.0

USE_LANGUAGES=	# none

ICON_THEMES=	yes

DEPENDS+=	faba-icon-theme-[0-9]*:../../graphics/faba-icon-theme

REPLACE_PYTHON+=	meson/post_install.py

# Requires Python 3
PYTHON_VERSIONS_INCOMPATIBLE=	27
PYTHON_FOR_BUILD_ONLY=		tool

# Save some time...
CHECK_WRKREF_SKIP+=		share/icons/Moka/*/*/*.png
CHECK_INTERPRETER_SKIP+=	share/icons/Moka/*/*/*.png

.include "../../devel/meson/build.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
