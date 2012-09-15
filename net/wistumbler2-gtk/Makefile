# $NetBSD: Makefile,v 1.20 2012/09/15 10:06:08 obache Exp $
#

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../net/wistumbler2/Makefile.common"

PKGNAME=		${DISTNAME:S/wistumbler2-/wistumbler2-gtk-/}
PKGREVISION=		14

CONFLICTS+=		wistumbler2-[0-9]*

USE_TOOLS+=		pkg-config

.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
