# $NetBSD: Makefile,v 1.13 2022/06/30 11:18:16 nia Exp $

DISTNAME=	mm-common-1.0.4
PKGREVISION=	1
CATEGORIES=	devel gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/mm-common/${PKGVERSION_NOREV:R}/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.gtkmm.org/
COMMENT=	Provides build infrastructure utilities for GNOME C++ libraries
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	c++
USE_TOOLS+=	gzip pkg-config

PYTHON_VERSIONS_INCOMPATIBLE=	27

REPLACE_PYTHON+=	util/build_scripts/dist-build-scripts.py
REPLACE_PYTHON+=	util/build_scripts/dist-changelog.py
REPLACE_PYTHON+=	util/build_scripts/doc-reference.py
REPLACE_PYTHON+=	util/build_scripts/generate-binding.py
REPLACE_PYTHON+=	util/doc_install.py
REPLACE_PYTHON+=	util/doc_postprocess.py
REPLACE_PYTHON+=	util/mm-common-get.in

.include "../../lang/python/application.mk"
.include "../../devel/meson/build.mk"
.include "../../mk/bsd.pkg.mk"
