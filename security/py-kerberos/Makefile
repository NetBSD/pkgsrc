# $NetBSD: Makefile,v 1.5 2021/01/09 08:18:09 adam Exp $

DISTNAME=	kerberos-1.3.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_PYPI:=k/kerberos/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/apple/ccs-pykerberos
COMMENT=	Python Kerberos implementation
LICENSE=	apache-2.0

.include "../../lang/python/egg.mk"
.include "../../mk/krb5.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
