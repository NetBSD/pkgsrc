# $NetBSD: Makefile,v 1.1 2023/05/04 10:51:34 wiz Exp $

DISTNAME=	py-serializable-0.12.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py-//}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/py-serializable/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/madpah/serializable
COMMENT=	Library for (de)serializing Python Objects to and from JSON and XML
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-defusedxml>=0.7.1<0.8.0:../../textproc/py-defusedxml

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
