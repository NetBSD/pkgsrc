# $NetBSD: Makefile,v 1.5 2022/01/01 12:29:27 martin Exp $

DISTNAME=	ptyprocess-0.7.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	sysutils python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/ptyprocess/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pexpect/ptyprocess
COMMENT=	Run a subprocess in a pseudo terminal
LICENSE=	isc

USE_LANGUAGES=	# none

do-test:
	cd ${WRKSRC} && ${PYTHONBIN} -m unittest tests/test_*

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
