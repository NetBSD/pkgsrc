# $NetBSD: Makefile,v 1.41 2001/02/17 17:42:15 wiz Exp $
# FreeBSD Id: Makefile,v 1.16 1997/11/30 19:37:48 vanilla Exp
#

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
