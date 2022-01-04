# $NetBSD: Makefile,v 1.10 2022/01/04 20:54:30 wiz Exp $

PKGREVISION= 1
.include "../../net/net-snmp/Makefile.common"

PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/net-snmp/netsnmp/}
CATEGORIES=	net python

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Python bindings to extensible SNMP implementation

PYTHON_VERSIONS_ACCEPTED=	27

USE_LANGUAGES=		c
EGG_NAME=		netsnmp_python-1.0a1
PYSETUPSUBDIR=		python

.include "../../net/net-snmp/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
