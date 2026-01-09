# $NetBSD: Makefile,v 1.7 2026/01/09 06:08:29 adam Exp $

DISTNAME=	cogapp-3.6.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/cogapp/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://nedbatchelder.com/code/cog
COMMENT=	Code generator for executing Python snippets in source files
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=80:../../devel/py-setuptools

USE_LANGUAGES=	# none

post-install:
	cd ${DESTDIR}${PREFIX}/bin && ${MV} cog cog-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
