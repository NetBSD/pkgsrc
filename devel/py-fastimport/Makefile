# $NetBSD: Makefile,v 1.1 2015/06/07 08:19:04 wiz Exp $

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

PYTHON_VERSIONS_INCOMPATIBLE=	33 34 # not yet ported as of 0.9.4

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
