# $NetBSD: Makefile,v 1.2 2016/11/28 23:38:18 joerg Exp $

GITHUB_TAG=	0.19
DISTNAME=	${GITHUB_TAG}
PKGNAME=	${PYPKGPREFIX}-gandi.cli-${GITHUB_TAG}
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=Gandi/}
GITHUB_PROJECT=	gandi.cli
DIST_SUBDIR=	gandi.cli
EGG_NAME=	gandi.cli-${GITHUB_TAG}

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	https://github.com/Gandi/gandi.cli
COMMENT=	Command line interface for Gandi.net
LICENSE=	gnu-gpl-v3

PYTHON_VERSIONS_ACCEPTED=	27

DEPENDS+=	${PYPKGPREFIX}-click>=3.1:../../devel/py-click
DEPENDS+=	${PYPKGPREFIX}-requests-[0-9]*:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-IP-[0-9]*:../../net/py-IP
DEPENDS+=	${PYPKGPREFIX}-yaml>=3.10:../../textproc/py-yaml

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
