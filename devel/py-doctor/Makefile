# $NetBSD: Makefile,v 1.15 2022/01/04 20:53:01 wiz Exp $

DISTNAME=	pydoctor-16.3.0
PKGNAME=	${DISTNAME:S/py/${PYPKGPREFIX}-/}
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pydoctor/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/twisted/pydoctor
COMMENT=	API doc generator
LICENSE=	mit

DEPENDS+=	epydoc-[0-9]*:../../devel/epydoc
DEPENDS+=	${PYPKGPREFIX}-twisted-[0-9]*:../../net/py-twisted

USE_LANGUAGES=	# none

PYTHON_VERSIONS_ACCEPTED=	27 # epydoc

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
