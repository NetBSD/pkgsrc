# $NetBSD: Makefile,v 1.5 2022/01/04 20:53:16 wiz Exp $

DISTNAME=	pymacaroons-${PKGVERSION_NOREV}
PKGNAME=	${PYPKGPREFIX}-macaroons-0.13.0
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pymacaroons/}

MAINTAINER=	js@pkgsrc.org
HOMEPAGE=	https://github.com/matrix-org/
COMMENT=	Python implementation of Macaroons
LICENSE=	mit

USE_LANGUAGES=	# empty

DEPENDS+=	${PYPKGPREFIX}-six>=1.8.0:../../lang/py-six
DEPENDS+=	${PYPKGPREFIX}-nacl>=1.1.2:../../security/py-nacl

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
