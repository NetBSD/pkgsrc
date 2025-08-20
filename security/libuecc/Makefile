# $NetBSD: Makefile,v 1.2 2025/08/20 11:35:10 wiz Exp $

DISTNAME=	libuecc-7
CATEGORIES=	security
MASTER_SITES=	https://git.universe-factory.net/libuecc/snapshot/
EXTRACT_SUFX=	.tar

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://git.universe-factory.net/libuecc/
COMMENT=	Very small Elliptic Curve Cryptography library
LICENSE=	2-clause-bsd

USE_CMAKE=	yes

PKGCONFIG_OVERRIDE+=	libuecc.pc.in

CMAKE_CONFIGURE_ARGS+=	-DCMAKE_POLICY_VERSION_MINIMUM=3.5

.include "../../mk/bsd.pkg.mk"
