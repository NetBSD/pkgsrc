# $NetBSD: Makefile,v 1.9 2022/01/04 20:54:42 wiz Exp $

DISTNAME=	kerberos-1.3.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_PYPI:=k/kerberos/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/apple/ccs-pykerberos
COMMENT=	Python Kerberos implementation
LICENSE=	apache-2.0

# When updating, try to build with the following:
#CFLAGS+=	-Werror=implicit-function-declaration

.include "../../lang/python/egg.mk"
.include "../../mk/krb5.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
