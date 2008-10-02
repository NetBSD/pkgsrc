# $NetBSD: Makefile,v 1.9 2008/10/02 13:35:02 joerg Exp $
#

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../net/wistumbler2/Makefile.common"

PKGNAME=		${DISTNAME:S/wistumbler2-/wistumbler2-gtk-/}
PKGREVISION=		3

CONFLICTS+=		wistumbler2-[0-9]*

USE_TOOLS+=		pkg-config

.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
