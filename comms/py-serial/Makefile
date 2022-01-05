# $NetBSD: Makefile,v 1.11 2022/01/05 15:40:58 wiz Exp $

DISTNAME=	pyserial-3.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/^py//}
PKGREVISION=	2
CATEGORIES=	comms python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pyserial/}

MAINTAINER=	tsarna@NetBSD.org
HOMEPAGE=	https://github.com/pyserial/pyserial
COMMENT=	Python Serial Port Extension
LICENSE=	modified-bsd

CONFLICTS+=	${PYPKGPREFIX}-pyserial-[0-9]*

USE_LANGUAGES=	# none

REPLACE_PYTHON=	serial/*.py serial/*/*.py

USE_PKG_RESOURCES=	yes

post-install:
.for bin in pyserial-miniterm pyserial-ports
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} ${bin} ${bin}-${PYVERSSUFFIX} || ${TRUE}
.endfor

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
