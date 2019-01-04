# $NetBSD: Makefile,v 1.3 2019/01/04 23:00:10 adam Exp $

DISTNAME=	uncompyle6-3.2.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	lang python
MASTER_SITES=	${MASTER_SITE_PYPI:=u/uncompyle6/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/rocky/python-uncompyle6
COMMENT=	Python cross-version byte-code decompiler
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-spark-parser>=1.8.7:../../lang/py-spark-parser
DEPENDS+=	${PYPKGPREFIX}-xdis>=3.8.9:../../devel/py-xdis

USE_LANGUAGES=	# none

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
		${MV} pydisassemble pydisassemble-${PYVERSSUFFIX} && \
		${MV} uncompyle6 uncompyle6-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
