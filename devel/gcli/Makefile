# $NetBSD: Makefile,v 1.7 2024/11/01 12:52:05 wiz Exp $

DISTNAME=	gcli-2.2.0
PKGREVISION=	4
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
