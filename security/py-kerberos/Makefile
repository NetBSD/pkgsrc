# $NetBSD: Makefile,v 1.1 2016/06/09 02:06:18 markd Exp $

DISTNAME=	kerberos-1.2.4
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
