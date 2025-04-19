# $NetBSD: Makefile,v 1.10 2025/04/19 07:57:41 wiz Exp $

DISTNAME=	gcli-2.2.0
PKGREVISION=	7
CATEGORIES=	devel
MASTER_SITES=	https://herrhotzenplotz.de/gcli/releases/gcli-2.2.0/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tm@NetBSD.org
HOMEPAGE=	https://herrhotzenplotz.de/gcli/
COMMENT=	Portable CLI tool for interacting with GitHub/Lab/Tea
LICENSE=	2-clause-bsd

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=	libgcli.pc.in

.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
