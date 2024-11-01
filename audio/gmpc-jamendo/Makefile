# $NetBSD: Makefile,v 1.50 2024/11/01 00:50:40 wiz Exp $

DISTNAME=	gmpc-jamendo-11.8.16
PKGREVISION=	46
CATEGORIES=	audio
MASTER_SITES=	https://download.sarine.nl/Programs/gmpc/11.8/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://gmpc.wikia.com/wiki/GMPC_PLUGIN_JAMENDO
COMMENT=	Jamendo plugin for GMPC
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	intltool msgfmt pkg-config

.include "../../audio/gmpc/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
