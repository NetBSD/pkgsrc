# $NetBSD: Makefile,v 1.6 2021/07/20 17:43:12 wiz Exp $

DISTNAME=	kerberos-1.3.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_PYPI:=k/kerberos/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/apple/ccs-pykerberos
COMMENT=	Python Kerberos implementation
LICENSE=	apache-2.0

# uses krb5_free_keytab_entry_contents, which only mit-krb5 provides
KRB5_ACCEPTED=	mit-krb5

.include "../../lang/python/egg.mk"
.include "../../mk/krb5.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
