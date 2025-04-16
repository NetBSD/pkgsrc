# $NetBSD: Makefile,v 1.16 2025/04/16 14:31:31 adam Exp $

DISTNAME=	rsa-4.9.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_PYPI:=r/rsa/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/sybrenstuvel/python-rsa
COMMENT=	Pure-Python RSA implementation
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-asn1>=0.1.3:../../security/py-asn1

USE_LANGUAGES=	# none

post-install:
.for bin in decrypt encrypt keygen priv2pub sign verify
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} pyrsa-${bin} pyrsa-${bin}-${PYVERSSUFFIX} || ${TRUE}
.endfor

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
