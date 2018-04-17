# $NetBSD: Makefile,v 1.7 2018/04/17 13:24:16 adam Exp $

DISTNAME=	fastimport-0.9.8
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=f/fastimport/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jelmer/python-fastimport
COMMENT=	Fastimport parser and generator in Python
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	# none

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
		${MV} fast-import-filter fast-import-filter-${PYVERSSUFFIX} && \
		${MV} fast-import-info fast-import-info-${PYVERSSUFFIX} && \
		${MV} fast-import-query fast-import-query-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
