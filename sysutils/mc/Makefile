# $NetBSD: Makefile,v 1.44 2003/07/13 13:53:19 wiz Exp $
# FreeBSD Id: Makefile,v 1.16 1997/11/30 19:37:48 vanilla Exp
#

PKGREVISION=		4
COMMENT=		Midnight Commander, a free Norton Commander Clone

CONFIGURE_ARGS+=	--without-x
CONFIGURE_ARGS+=	--without-tm-x-support
CONFIGURE_ARGS+=	--without-gnome

# Remove unwanted directories in a non-GNOME installation.
#
post-install:
	cd ${PREFIX}; ${RMDIR} -p share/idl 2>/dev/null || ${TRUE}
	cd ${PREFIX}; ${RMDIR} -p share/pixmaps/mc 2>/dev/null || ${TRUE}

.include "../../sysutils/mc/Makefile.common"
