# $NetBSD: Makefile,v 1.4 2005/07/21 16:29:55 wiz Exp $
#

.include "../../net/wistumbler2/Makefile.common"

PKGNAME=		${DISTNAME:S/wistumbler2-/wistumbler2-gtk-/}

CONFLICTS+=		wistumbler2-[0-9]*

.include "../../devel/pkg-config/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
