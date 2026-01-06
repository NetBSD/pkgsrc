# $NetBSD: Makefile,v 1.3 2026/01/06 08:42:22 wiz Exp $

DISTNAME=	libuecc-7
CATEGORIES=	security
MASTER_SITES=	https://git.universe-factory.net/fastd/libuecc/snapshot/
EXTRACT_SUFX=	.tar

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://git.universe-factory.net/fastd/libuecc
COMMENT=	Very small Elliptic Curve Cryptography library
LICENSE=	2-clause-bsd

USE_CMAKE=	yes

PKGCONFIG_OVERRIDE+=	libuecc.pc.in

CMAKE_CONFIGURE_ARGS+=	-DCMAKE_POLICY_VERSION_MINIMUM=3.5

.include "../../mk/bsd.pkg.mk"
