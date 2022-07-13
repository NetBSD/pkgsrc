# $NetBSD: Makefile,v 1.1 2022/07/13 12:11:00 adam Exp $

DISTNAME=	invoke-1.7.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	sysutils python
MASTER_SITES=	${MASTER_SITE_PYPI:=i/invoke/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pyinvoke.org/
COMMENT=	Pythonic task execution
LICENSE=	modified-bsd

USE_LANGUAGES=	# none

post-install:
.for bin in inv invoke
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} ${bin} ${bin}-${PYVERSSUFFIX} || ${TRUE}
.endfor

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
