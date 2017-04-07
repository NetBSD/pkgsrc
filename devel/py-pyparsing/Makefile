# $NetBSD: Makefile,v 1.10 2017/04/07 03:35:12 adam Exp $

DISTNAME=	pyparsing-2.2.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pyparsing/}
MASTER_SITES+=	${MASTER_SITE_PYPI:=p/pyparsing/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://pyparsing.wikispaces.com/
COMMENT=	Parsing module for Python
LICENSE=	mit

USE_LANGUAGES=		# none
BOOTSTRAP_SETUPTOOLS=	yes

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
