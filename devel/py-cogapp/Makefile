# $NetBSD: Makefile,v 1.3 2023/07/22 21:46:57 yhardy Exp $

DISTNAME=	cogapp-3.3.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/cogapp/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://nedbatchelder.com/code/cog
COMMENT=	Code generator for executing Python snippets in source files
LICENSE=	mit

USE_LANGUAGES=	# none

post-install:
	cd ${DESTDIR}${PREFIX}/bin && ${MV} cog cog-${PYVERSSUFFIX} || ${TRUE}
	cd ${DESTDIR}${PREFIX}/bin && ${MV} cog.py cog-${PYVERSSUFFIX}.py || ${TRUE}

do-test:
	cd ${WRKSRC} && ${PYTHONBIN} -m unittest discover -v

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
