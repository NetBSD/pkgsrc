# $NetBSD: Makefile,v 1.2 2025/05/16 15:38:10 adam Exp $

DISTNAME=	synadm-0.48
CATEGORIES=	chat python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/synadm/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://codeberg.org/synadm/synadm
COMMENT=	Command line admin tool for Synapse
LICENSE=	gnu-gpl-v3

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-click>=7.1:../../devel/py-click
DEPENDS+=	${PYPKGPREFIX}-click-option-group>=0.5.2:../../devel/py-click-option-group
DEPENDS+=	${PYPKGPREFIX}-dns>0:../../net/py-dns
DEPENDS+=	${PYPKGPREFIX}-requests>0:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-tabulate>0:../../textproc/py-tabulate
DEPENDS+=	${PYPKGPREFIX}-yaml>0:../../textproc/py-yaml

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
