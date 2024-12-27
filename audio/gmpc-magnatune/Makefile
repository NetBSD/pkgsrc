# $NetBSD: Makefile,v 1.78 2024/12/27 08:19:20 wiz Exp $

DISTNAME=	gmpc-magnatune-11.8.16
PKGREVISION=	50
CATEGORIES=	audio
MASTER_SITES=	https://download.sarine.nl/Programs/gmpc/11.8/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://gmpc.wikia.com/wiki/GMPC_PLUGIN_MAGNATUNE
COMMENT=	Magnatune plugin for GMPC
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	intltool msgfmt pkg-config

.include "../../audio/gmpc/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
