# $NetBSD: Makefile,v 1.24 2023/12/28 23:44:05 zafer Exp $

DISTNAME=	gmpc-libnotify-11.8.16
PKGREVISION=	20
CATEGORIES=	audio
MASTER_SITES=	https://download.sarine.nl/Programs/gmpc/11.8/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://gmpc.wikia.com/wiki/GMPC_PLUGIN_LIBNOTIFY
COMMENT=	Alternate notification plugin for GMPC using libnotify
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	intltool msgfmt pkg-config

.include "../../audio/gmpc/buildlink3.mk"
.include "../../sysutils/libnotify/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
