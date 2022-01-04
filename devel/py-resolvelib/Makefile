# $NetBSD: Makefile,v 1.2 2022/01/04 20:53:36 wiz Exp $

DISTNAME=	resolvelib-0.8.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=r/resolvelib/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/sarugaku/resolvelib
COMMENT=	Resolve abstract dependencies into concrete ones
LICENSE=	isc

USE_LANGUAGES=	# none

post-install:
	${CHMOD} -R go-w ${DESTDIR}${PREFIX}/${PYSITELIB}/resolvelib

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
