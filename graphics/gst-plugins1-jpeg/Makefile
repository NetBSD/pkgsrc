# $NetBSD: Makefile,v 1.5 2021/11/17 08:36:03 wiz Exp $

PKGNAME=	${DISTNAME:S/plugins/plugins1/:S/-good/-jpeg/}
CATEGORIES=	graphics gnome

COMMENT=	Open source multimedia framework - JPEG plugin

GST_PLUGINS+=	jpeg

.include "../../multimedia/gst-plugins1-good/Makefile.common"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
