# $NetBSD: Makefile,v 1.6 2025/02/23 20:37:23 wiz Exp $

DISTNAME=	click_default_group-1.2.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/g}
PKGREVISION=	2
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/click-default-group/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/sublee/click-default-group
COMMENT=	Extends click.Group to invoke a command without explicit subcommand name
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-flit_core>=3.11:../../devel/py-flit_core
DEPENDS+=	${PYPKGPREFIX}-click>=0:../../devel/py-click

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
