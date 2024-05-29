# $NetBSD: Makefile,v 1.16 2024/05/29 16:33:52 adam Exp $

DISTNAME=		gnunet-gtk-0.21.0
PKGREVISION=		4
CATEGORIES=		net
MASTER_SITES=		${MASTER_SITE_GNU:=gnunet/}

MAINTAINER=		nikita@NetBSD.org
HOMEPAGE=		https://gnunet.org/
COMMENT=		GTK user interfaces for GNUnet
LICENSE=		gnu-gpl-v3

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		bash pkg-config

REPLACE_BASH+=		pixmaps/icon-theme-installer

# options.mk uses an option from gnunet's bl3
# TODO: verify if this still does anything
.include "../../net/gnunet/buildlink3.mk"
.include "options.mk"

CONFIGURE_ENV+=		LD_LIBRARY_PATH+=${BUILDLINK_PREFIX.gtk3}/lib
CONFIGURE_ARGS+=	--with-gnunet=${BUILDLINK_PREFIX.gnunet}
CONFIGURE_ARGS+=	--with-glade=${BUILDLINK_PREFIX.glade}
# optional dependency, but x11/libunique says it is deprecated.
# CONFIGURE_ARGS+=	--with-libunique

.include "../../converters/qrencode/buildlink3.mk"
.include "../../devel/glade/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../security/gnutls/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
