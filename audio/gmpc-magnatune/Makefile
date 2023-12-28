# $NetBSD: Makefile,v 1.70 2023/12/28 23:45:38 zafer Exp $

DISTNAME=	gmpc-magnatune-11.8.16
PKGREVISION=	42
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
