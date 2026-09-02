# $NetBSD: Makefile,v 1.57 2026/09/02 19:04:05 wiz Exp $
#

.include "../../net/wistumbler2/Makefile.common"

PKGNAME=		${DISTNAME:S/wistumbler2-/wistumbler2-gtk-/}
PKGREVISION=		50

CONFLICTS+=		wistumbler2-[0-9]*

USE_TOOLS+=		pkg-config

.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
