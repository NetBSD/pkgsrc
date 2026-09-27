# $NetBSD: Makefile,v 1.58 2026/09/27 11:38:12 tnn Exp $
#

.include "../../net/wistumbler2/Makefile.common"

PKGNAME=		${DISTNAME:S/wistumbler2-/wistumbler2-gtk-/}
PKGREVISION=		51

CONFLICTS+=		wistumbler2-[0-9]*

USE_TOOLS+=		pkg-config

.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
