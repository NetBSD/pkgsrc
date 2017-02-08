# $NetBSD: Makefile,v 1.9 2017/02/08 12:11:09 wiz Exp $

DISTNAME=	pyparsing-2.1.10
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pyparsing/}
MASTER_SITES+=	${MASTER_SITE_PYPI:=p/pyparsing/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://pyparsing.wikispaces.com/
COMMENT=	Pyparsing module for Python
LICENSE=	mit

USE_LANGUAGES=	# none
BOOTSTRAP_SETUPTOOLS=	yes

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
