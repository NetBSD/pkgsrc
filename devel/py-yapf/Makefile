# $NetBSD: Makefile,v 1.2 2020/05/18 08:36:30 wiz Exp $

DISTNAME=	yapf-0.30.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel textproc
MASTER_SITES=	${MASTER_SITE_PYPI:=y/yapf/}

MAINTAINER=	nils@NetBSD.org
HOMEPAGE=	https://github.com/google/yapf/
COMMENT=	Python files formatter
LICENSE=	apache-2.0

USE_LANGUAGES=	# none

post-install:
	${MV} ${DESTDIR}${PREFIX}/bin/yapf ${DESTDIR}${PREFIX}/bin/yapf-${PYVERSSUFFIX}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
