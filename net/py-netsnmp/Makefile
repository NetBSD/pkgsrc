# $NetBSD: Makefile,v 1.14 2024/02/21 10:21:01 wiz Exp $

.include "../../net/net-snmp/Makefile.common"

PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/net-snmp/netsnmp/}
CATEGORIES=	net python

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Python bindings to extensible SNMP implementation

USE_LANGUAGES=		c
EGG_NAME=		netsnmp_python-1.0a1
PYSETUPSUBDIR=		python

.include "../../net/net-snmp/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
