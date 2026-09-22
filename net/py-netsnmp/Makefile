# $NetBSD: Makefile,v 1.16 2026/09/22 20:46:42 wiz Exp $

.include "../../net/net-snmp/Makefile.common"

PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/net-snmp/netsnmp/}
CATEGORIES=	net python

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Python bindings to extensible SNMP implementation

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=0:../../devel/py-setuptools

PYSETUPSUBDIR=	python
WHEEL_NAME=	netsnmp_python-1.0a1

.include "../../lang/python/wheel.mk"
.include "../../net/net-snmp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
