# $NetBSD: Makefile,v 1.20 2022/01/04 20:52:38 wiz Exp $

DISTNAME=	python-gammu-2.12
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/python-//}
PKGREVISION=	1
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
