# $NetBSD: Makefile,v 1.65 2026/09/29 06:03:44 wiz Exp $

DISTNAME=	gmpc-albumview-11.8.16
PKGREVISION=	44
CATEGORIES=	audio
MASTER_SITES=	https://download.sarine.nl/Programs/gmpc/11.8/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://gmpc.wikia.com/wiki/GMPC_PLUGIN_ALBUMVIEW
COMMENT=	GMPC plugin showing album covers
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	intltool pkg-config msgfmt

CFLAGS+=	-Wno-incompatible-pointer-types
CFLAGS+=	-Wno-implicit-function-declaration

.include "../../audio/gmpc/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
