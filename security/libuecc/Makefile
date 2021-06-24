# $NetBSD: Makefile,v 1.1 2021/06/24 13:55:26 nia Exp $

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

.include "../../mk/bsd.pkg.mk"
