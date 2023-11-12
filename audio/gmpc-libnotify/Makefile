# $NetBSD: Makefile,v 1.22 2023/11/12 13:20:37 wiz Exp $

DISTNAME=	gmpc-libnotify-11.8.16
PKGREVISION=	19
CATEGORIES=	audio
MASTER_SITES=	http://download.sarine.nl/Programs/gmpc/11.8/
MASTER_SITES+=	${MASTER_SITE_SOURCEFORGE:=musicpd/}

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
