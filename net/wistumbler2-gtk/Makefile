# $NetBSD: Makefile,v 1.15 2011/04/22 13:44:29 obache Exp $
#

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../net/wistumbler2/Makefile.common"

PKGNAME=		${DISTNAME:S/wistumbler2-/wistumbler2-gtk-/}
PKGREVISION=		9

CONFLICTS+=		wistumbler2-[0-9]*

USE_TOOLS+=		pkg-config

.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
