# $NetBSD: Makefile,v 1.13 2024/06/05 22:44:57 wiz Exp $

DISTNAME=	pyserial-3.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/^py//}
PKGREVISION=	2
CATEGORIES=	comms python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pyserial/}

MAINTAINER=	tsarna@NetBSD.org
HOMEPAGE=	https://github.com/pyserial/pyserial
COMMENT=	Python Serial Port Extension
LICENSE=	modified-bsd

CONFLICTS+=	py[0-9]*-pyserial-[0-9]*

USE_LANGUAGES=	# none

REPLACE_PYTHON=	serial/*.py serial/*/*.py

USE_PKG_RESOURCES=	yes
PYTHON_27_ACCEPTED=	yes

post-install:
.for bin in pyserial-miniterm pyserial-ports
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} ${bin} ${bin}-${PYVERSSUFFIX} || ${TRUE}
.endfor

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
