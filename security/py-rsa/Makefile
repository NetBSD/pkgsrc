# $NetBSD: Makefile,v 1.15 2022/07/24 10:48:55 wiz Exp $

DISTNAME=	rsa-4.9
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_PYPI:=r/rsa/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/sybrenstuvel/python-rsa
COMMENT=	Pure-Python RSA implementation
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-asn1>=0.1.3:../../security/py-asn1

PYTHON_VERSIONS_INCOMPATIBLE=	27

USE_PKG_RESOURCES=	yes

USE_LANGUAGES=	# none

post-install:
.for bin in decrypt encrypt keygen priv2pub sign verify
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} pyrsa-${bin} pyrsa-${bin}-${PYVERSSUFFIX} || ${TRUE}
.endfor

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
