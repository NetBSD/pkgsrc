# $NetBSD: Makefile,v 1.4 2022/01/04 20:53:23 wiz Exp $

DISTNAME=	pycotap-1.2.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pycotap/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://el-tramo.be/pycotap
COMMENT=	Tiny test runner that outputs TAP results to standard output
LICENSE=	mit

USE_LANGUAGES=	# none

INSTALLATION_DIRS=	share/doc/${PYPKGPREFIX}-pycotap

PLIST_SUBST+=	PYPKGPREFIX=${PYPKGPREFIX}

post-install:
	${MV} ${DESTDIR}${PREFIX}/COPYING ${DESTDIR}${PREFIX}/share/doc/${PYPKGPREFIX}-pycotap/

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
