# $NetBSD: Makefile,v 1.9 2022/01/04 20:53:06 wiz Exp $

DISTNAME=	funcparserlib-0.3.6
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PYPI:=f/funcparserlib/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/vlasovskikh/funcparserlib
COMMENT=	Recursive descent parsing library based on functional combinators
LICENSE=	mit

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"

.if ${PYPKGPREFIX} != "py27"
pre-build:
	cd ${WRKSRC} && 2to3-${PYVERSSUFFIX} -w --no-diffs funcparserlib
.endif

.include "../../mk/bsd.pkg.mk"
