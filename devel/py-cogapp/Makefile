# $NetBSD: Makefile,v 1.2 2022/01/04 20:52:57 wiz Exp $

DISTNAME=	cogapp-2.5.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/cogapp/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://nedbatchelder.com/code/cog
COMMENT=	Code generator for executing Python snippets in source files
LICENSE=	mit

USE_LANGUAGES=	# none

post-install:
	cd ${DESTDIR}${PREFIX}/bin && ${MV} cog.py cog-${PYVERSSUFFIX} || ${TRUE}

do-test:
	cd ${WRKSRC} && ${PYTHONBIN} -m unittest discover -v

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
