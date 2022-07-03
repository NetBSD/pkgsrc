# $NetBSD: Makefile,v 1.78 2022/07/03 10:13:49 wiz Exp $

DISTNAME=	libgpod-0.8.3
PKGREVISION=	4
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gtkpod/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	srp@tworoads.net
HOMEPAGE=	https://sourceforge.net/projects/gtkpod/
COMMENT=	Library for accessing iPod onboard databases, playlists, etc
LICENSE=	gnu-lgpl-v2

PKGCONFIG_OVERRIDE=	libgpod-1.0.pc.in

USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake intltool msgfmt pkg-config
GNU_CONFIGURE=		yes

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} != "Linux"
CONFIGURE_ARGS+=	--disable-udev
.endif

.include "../../databases/sqlite3/buildlink3.mk"
BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.15.0
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../textproc/libplist/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
