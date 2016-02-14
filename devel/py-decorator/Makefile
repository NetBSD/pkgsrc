# $NetBSD: Makefile,v 1.7 2016/02/14 11:02:10 wiz Exp $

DISTNAME=		decorator-4.0.9
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=		devel python
MASTER_SITES=		http://pypi.python.org/packages/source/d/decorator/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://pypi.python.org/pypi/decorator
COMMENT=		Generic Python decorator utilities
LICENSE=		2-clause-bsd

# bug in 4.0.9 distfile
post-extract:
	${RM} -f ${WRKSRC}/src/decorator.egg-info/SOURCES.txt~

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
