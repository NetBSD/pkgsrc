# $NetBSD: Makefile,v 1.11 2022/01/04 20:53:04 wiz Exp $

DISTNAME=	fastimport-0.9.14
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=f/fastimport/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jelmer/python-fastimport
COMMENT=	Fastimport parser and generator in Python
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

post-install:
.for bin in fast-import-filter fast-import-info fast-import-query
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} ${bin} ${bin}-${PYVERSSUFFIX} || ${TRUE}
.endfor

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
