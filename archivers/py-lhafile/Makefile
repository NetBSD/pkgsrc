# $NetBSD: Makefile,v 1.2 2017/08/01 14:58:51 wiz Exp $

DISTNAME=	python-lhafile
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/python-//}-0.2.1
CATEGORIES=	archivers python
MASTER_SITES=	${MASTER_SITE_GITHUB:=FrodeSolheim/}
GITHUB_PROJECT=	${DISTNAME}
GITHUB_TAG=	a7341c16a2028bce547b6c06df8d455af29fcab6
EXTRACT_SUFX=	.zip

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	https://fs-uae.net/
COMMENT=	LHA(.lzh) file extract interface
LICENSE=	modified-bsd

USE_LANGUAGES=		c
PYDISTUTILSPKG=		yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
