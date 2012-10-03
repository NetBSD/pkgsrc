# $NetBSD: Makefile,v 1.20.2.1 2012/10/03 12:09:11 spz Exp $
#

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../net/wistumbler2/Makefile.common"

PKGNAME=		${DISTNAME:S/wistumbler2-/wistumbler2-gtk-/}
PKGREVISION=		15

CONFLICTS+=		wistumbler2-[0-9]*

USE_TOOLS+=		pkg-config

.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
