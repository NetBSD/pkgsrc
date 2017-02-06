# $NetBSD: Makefile,v 1.4 2017/02/06 13:54:47 wiz Exp $

PKGREVISION= 3
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
