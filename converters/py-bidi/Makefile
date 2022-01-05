# $NetBSD: Makefile,v 1.3 2022/01/05 15:40:58 wiz Exp $

DISTNAME=	python-bidi-0.4.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/^python-//}
PKGREVISION=	2
CATEGORIES=	converters python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/python-bidi/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/MeirKriheli/python-bidi
COMMENT=	Pure Python implementation of the BiDi layout algorithm
LICENSE=	gnu-lgpl-v2.1

DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six

USE_LANGUAGES=	# none

USE_PKG_RESOURCES=	yes

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} pybidi pybidi-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
