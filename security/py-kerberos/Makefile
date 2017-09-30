# $NetBSD: Makefile,v 1.3 2017/09/30 09:42:52 adam Exp $

DISTNAME=	kerberos-1.2.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_PYPI:=k/kerberos/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://svn.calendarserver.org/wiki/PyKerberos
COMMENT=	Python Kerberos implementation
LICENSE=	apache-2.0

.include "../../lang/python/egg.mk"
.include "../../mk/krb5.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
