# $NetBSD: Makefile,v 1.5 2022/01/10 23:46:49 wiz Exp $

DISTNAME=		python-lua
PKGNAME=		${PYPKGPREFIX}-python-lua-20170109
PKGREVISION=		1
CATEGORIES=		lang converters
MASTER_SITES=		${MASTER_SITE_GITHUB:=NeonMercury/}
DIST_SUBDIR=		${DISTNAME}
GITHUB_PROJECT=		${DISTNAME}
GITHUB_TAG=		9e5657932708d7f5cf6531cb21afc81c4708d3ac
EXTRACT_SUFX=		.zip

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://github.com/NeonMercury/python-lua
COMMENT=		Simple python to lua translator
LICENSE=		apache-2.0

BUILD_DEPENDS+=		${PYPKGPREFIX}-yaml>=3.12:../../textproc/py-yaml

USE_LANGUAGES=		#none

PYTHON_VERSIONS_INCOMPATIBLE= 27
PYTHON_VERSIONED_DEPENDENCIES+=	setuptools:build
REPLACE_PYTHON=		pythonlua/*.py tests/*.py *.py

AUTO_MKDIRS=		yes

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/__main__.py ${DESTDIR}${PREFIX}/bin/pythonlua
	${INSTALL_SCRIPT} ${WRKSRC}/pythonlua/luainit.lua ${DESTDIR}${PREFIX}/${PYSITELIB}/pythonlua

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
