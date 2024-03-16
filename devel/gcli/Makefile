# $NetBSD: Makefile,v 1.1 2024/03/16 09:01:24 tm Exp $

DISTNAME=	gcli-2.2.0
CATEGORIES=	devel
MASTER_SITES=	https://herrhotzenplotz.de/gcli/releases/gcli-2.2.0/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tm@NetBSD.org
HOMEPAGE=	https://herrhotzenplotz.de/gcli/releases/gcli-2.2.0/
COMMENT=	Portable CLI tool for interacting with Git(Hub|Lab|Tea)
LICENSE=	2-clause-bsd

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=	libgcli.pc.in

.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
