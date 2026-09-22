# $NetBSD: Makefile,v 1.15 2026/09/22 07:42:21 adam Exp $

.include "../../net/net-snmp/Makefile.common"

PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/net-snmp/netsnmp/}
CATEGORIES=	net python

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Python bindings to extensible SNMP implementation

PYSETUPSUBDIR=	python
WHEEL_NAME=	netsnmp_python-1.0a1

.include "../../lang/python/wheel.mk"
.include "../../net/net-snmp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
