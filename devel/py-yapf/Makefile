# $NetBSD: Makefile,v 1.6 2022/01/05 15:41:09 wiz Exp $

DISTNAME=	yapf-0.32.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=y/yapf/}

MAINTAINER=	nils@NetBSD.org
HOMEPAGE=	https://github.com/google/yapf
COMMENT=	Python files formatter
LICENSE=	apache-2.0

USE_LANGUAGES=	# none

USE_PKG_RESOURCES=	yes

post-install:
.for bin in yapf yapf-diff
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} ${bin} ${bin}-${PYVERSSUFFIX} || ${TRUE}
.endfor

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
