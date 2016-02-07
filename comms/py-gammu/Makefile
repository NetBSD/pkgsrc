# $NetBSD: Makefile,v 1.11 2016/02/07 15:30:40 leot Exp $

DISTNAME=	python-gammu-2.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/python-//}
MASTER_SITES=	http://dl.cihar.com/python-gammu/
CATEGORIES=	comms

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://wammu.eu/gammu/
COMMENT=	Python bindings for gammu
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	pkg-config

# UnicodeDecodeError: 'ascii' codec can't decode byte 0xc4 in position 1648: ordinal not in range(128)
PYTHON_VERSIONS_INCOMPATIBLE=	33 34 35

.include "../../lang/python/egg.mk"
.include "../../comms/gammu/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
