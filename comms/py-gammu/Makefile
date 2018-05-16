# $NetBSD: Makefile,v 1.18 2018/05/16 08:25:43 leot Exp $

DISTNAME=	python-gammu-2.11
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/python-//}
MASTER_SITES=	http://dl.cihar.com/python-gammu/
CATEGORIES=	comms

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://wammu.eu/gammu/
COMMENT=	Python bindings for gammu
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	pkg-config

.include "../../lang/python/egg.mk"
.include "../../comms/gammu/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
