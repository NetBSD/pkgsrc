# $NetBSD: Makefile,v 1.4 2019/01/04 23:04:25 adam Exp $

DISTNAME=	kerberos-1.3.0
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
