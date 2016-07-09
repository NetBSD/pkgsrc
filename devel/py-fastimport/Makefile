# $NetBSD: Makefile,v 1.3 2016/07/09 13:03:41 wiz Exp $

DISTNAME=	fastimport-0.9.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel scm
MASTER_SITES=	${MASTER_SITE_GITHUB:=jelmer/}
GITHUB_PROJECT=	python-fastimport
GITHUB_TAG=	${DISTNAME}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jelmer/python-fastimport
COMMENT=	Fastimport parser and generator in Python
LICENSE=	gnu-gpl-v2

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 # not yet ported as of 0.9.4

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
