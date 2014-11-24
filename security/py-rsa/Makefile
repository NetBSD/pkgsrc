# $NetBSD: Makefile,v 1.1 2014/11/24 14:38:03 wiz Exp $

DISTNAME=	rsa-3.1.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	security python
MASTER_SITES=	https://pypi.python.org/packages/source/r/rsa/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://stuvel.eu/rsa
COMMENT=	Pure-Python RSA implementation
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-asn1-[0-9]*:../../security/py-asn1

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
