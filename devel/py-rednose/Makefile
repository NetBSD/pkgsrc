# $NetBSD: Makefile,v 1.7 2023/07/01 08:53:22 wiz Exp $

DISTNAME=	rednose-1.2.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=r/rednose/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/JBKahn/rednose
COMMENT=	Coloured output for nosetests
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-colorama-[0-9]*:../../comms/py-colorama
DEPENDS+=	${PYPKGPREFIX}-termstyle>=0.1.7:../../comms/py-termstyle

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
