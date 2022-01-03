# $NetBSD: Makefile,v 1.1 2022/01/03 10:49:09 wiz Exp $

DISTNAME=	pycotap-1.2.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pycotap/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://el-tramo.be/pycotap
COMMENT=	Tiny test runner that outputs TAP results to standard output
LICENSE=	mit

#BUILD_DEPENDS+=	${PYPKGPREFIX}-test-runner-[0-9]*:../../devel/py-test-runner
#DEPENDS+=		${PYPKGPREFIX}-wcwidth>=0.1.7:../../devel/py-wcwidth

USE_LANGUAGES=	# none

INSTALLATION_DIRS=	share/doc/${PYPKGPREFIX}-pycotap

post-install:
	${MV} ${DESTDIR}${PREFIX}/COPYING ${DESTDIR}${PREFIX}/share/doc/${PYPKGPREFIX}-pycotap/

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
