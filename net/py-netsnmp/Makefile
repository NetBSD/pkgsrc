# $NetBSD: Makefile,v 1.3 2015/12/05 21:25:54 adam Exp $

.include "../../net/net-snmp/Makefile.common"

PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/net-snmp/netsnmp/}
CATEGORIES=     net python

MAINTAINER=     pkgsrc-users@NetBSD.org
COMMENT=        Python bindings to extensible SNMP implementation

PYTHON_VERSIONS_INCOMPATIBLE=   33 34 35

USE_LANGUAGES=  	c
EGG_NAME=		netsnmp_python-1.0a1
PYSETUPSUBDIR=		python

.include "../../net/net-snmp/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
