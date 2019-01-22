# $NetBSD: Makefile,v 1.13 2019/01/22 10:29:46 adam Exp $

DISTNAME=	pydoctor-16.3.0
PKGNAME=	${DISTNAME:S/py/${PYPKGPREFIX}-/}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pydoctor/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://github.com/twisted/pydoctor
COMMENT=	API doc generator
LICENSE=	mit

DEPENDS+=	epydoc-[0-9]*:../../devel/epydoc
DEPENDS+=	${PYPKGPREFIX}-twisted-[0-9]*:../../net/py-twisted

USE_LANGUAGES=	# none

PYTHON_VERSIONS_ACCEPTED=	27 # epydoc

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
