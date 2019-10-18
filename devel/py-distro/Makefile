# $NetBSD: Makefile,v 1.2.2.2 2019/10/18 14:31:38 bsiegert Exp $

DISTNAME=	distro-1.4.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/distro/}

MAINTAINER=	root@zta.lk
HOMEPAGE=	https://github.com/nir0s/distro
COMMENT=	OS platform information API
LICENSE=	apache-2.0

USE_LANGUAGES=	# none

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} distro distro-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
