# $NetBSD: Makefile,v 1.6 2026/09/02 19:03:43 wiz Exp $

PKGNAME=	${DISTNAME:S/plugins/plugins1/:S/-bad/-openh264/}
PKGREVISION=	1
CATEGORIES=	multimedia gnome

COMMENT=	Open source multimedia framework - H.264/MPEG-4 decoder plugin

GST_EXT_BUILD=	# defined
GST_PLUGINS+=	openh264

.include "../../multimedia/gst-plugins1-bad/Makefile.common"
.include "../../multimedia/openh264/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
