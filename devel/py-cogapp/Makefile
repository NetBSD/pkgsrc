# $NetBSD: Makefile,v 1.6 2025/04/12 09:50:45 adam Exp $

DISTNAME=	cogapp-3.4.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/cogapp/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://nedbatchelder.com/code/cog
COMMENT=	Code generator for executing Python snippets in source files
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools

USE_LANGUAGES=	# none

post-install:
	cd ${DESTDIR}${PREFIX}/bin && ${MV} cog cog-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
