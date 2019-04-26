# $NetBSD: Makefile,v 1.7 2019/04/26 13:14:09 maya Exp $

.include "../../net/net-snmp/Makefile.common"

PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/net-snmp/netsnmp/}
CATEGORIES=     net python

MAINTAINER=     pkgsrc-users@NetBSD.org
COMMENT=        Python bindings to extensible SNMP implementation

PYTHON_VERSIONS_INCOMPATIBLE=    36 37

USE_LANGUAGES=  	c
EGG_NAME=		netsnmp_python-1.0a1
PYSETUPSUBDIR=		python

.include "../../net/net-snmp/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
