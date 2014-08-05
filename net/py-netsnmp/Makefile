# $NetBSD: Makefile,v 1.1 2014/08/05 12:22:43 he Exp $

.include "../../net/net-snmp/Makefile.common"
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/net-snmp/netsnmp/}
CATEGORIES=     net python

MAINTAINER=     pkgsrc-users@NetBSD.org
COMMENT=        Python bindings to extensible SNMP implementation

WRKSRC=		${WRKDIR}/${DISTNAME}/python

USE_LANGUAGES=  c
EGG_NAME=	netsnmp_python-1.0a1
PYTHON_VERSIONS_INCOMPATIBLE=   33 34

.include "../../net/net-snmp/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
