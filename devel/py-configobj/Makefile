# $NetBSD: Makefile,v 1.11 2022/01/09 11:58:13 wiz Exp $

DISTNAME=	configobj-5.0.6
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/configobj/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/DiffSK/configobj
COMMENT=	Config file reading, writing and validation
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
