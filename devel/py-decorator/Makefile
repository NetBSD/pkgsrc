# $NetBSD: Makefile,v 1.10 2016/06/13 12:05:14 wiz Exp $

DISTNAME=	decorator-4.0.10
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/decorator/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://pypi.python.org/pypi/decorator
COMMENT=	Generic Python decorator utilities
LICENSE=	2-clause-bsd

# bug in 4.0.10 distfile
# https://github.com/micheles/decorator/issues/32
post-extract:
	${RM} -f ${WRKSRC}/src/decorator.egg-info/SOURCES.txt~

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
