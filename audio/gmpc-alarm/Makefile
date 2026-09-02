# $NetBSD: Makefile,v 1.34 2026/09/02 19:00:48 wiz Exp $

DISTNAME=	gmpc-alarm-11.8.16
PKGREVISION=	29
CATEGORIES=	audio
MASTER_SITES=	https://download.sarine.nl/Programs/gmpc/11.8/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://gmpc.wikia.com/wiki/GMPC_PLUGIN_ALARM
COMMENT=	Alarm Timer plugin for GMPC
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	intltool msgfmt pkg-config

CFLAGS+=	-Wno-implicit-function-declaration

.include "../../audio/gmpc/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
