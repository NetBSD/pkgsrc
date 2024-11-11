# $NetBSD: Makefile,v 1.5 2024/11/11 07:28:04 wiz Exp $

DISTNAME=	cogapp-3.4.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/cogapp/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://nedbatchelder.com/code/cog
COMMENT=	Code generator for executing Python snippets in source files
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

post-install:
	cd ${DESTDIR}${PREFIX}/bin && ${MV} cog cog-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
