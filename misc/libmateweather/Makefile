# $NetBSD: Makefile,v 1.1 2016/05/21 18:48:54 youri Exp $

.include "../../meta-pkgs/mate/Makefile.common"

DISTNAME=	libmateweather-${MATE_VERSION}
CATEGORIES=	misc

COMMENT=	Weather information access library

PKGCONFIG_OVERRIDE+=	libmateweather/mateweather.pc.in

.include "../../devel/glib2/schemas.mk"

.include "../../devel/glib2/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../net/libsoup/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
