# $NetBSD: Makefile,v 1.13 2012/01/14 02:09:37 hans Exp $
#
PKG_DESTDIR_SUPPORT=	user-destdir

.include "Makefile.common"
PKGREVISION=	1
USE_TOOLS+=	zip:run

INFO_FILES=		# PLIST

CONFIGURE_ARGS+=	--disable-gtk-peer

.include "../../mk/java-env.mk"
.include "../../mk/bsd.pkg.mk"
