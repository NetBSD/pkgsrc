# $NetBSD: Makefile,v 1.2 2017/04/23 05:35:27 markd Exp $

DISTNAME=	kerberos-1.2.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_PYPI:=k/kerberos/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://svn.calendarserver.org/wiki/PyKerberos
COMMENT=	Python Kerberos implementation
LICENSE=	apache-2.0

.include "../../lang/python/egg.mk"
.include "../../mk/krb5.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
