# $NetBSD: Makefile,v 1.6 2021/11/15 22:01:18 wiz Exp $

PKGNAME=	${DISTNAME:S/plugins/plugins1/:S/-good/-png/}
CATEGORIES=	graphics gnome

COMMENT=	Open source multimedia framework - PNG image plugin

GST_PLUGINS+=	png

.include "../../multimedia/gst-plugins1-good/Makefile.common"
.include "../../graphics/png/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
