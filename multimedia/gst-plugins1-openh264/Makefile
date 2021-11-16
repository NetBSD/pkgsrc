# $NetBSD: Makefile,v 1.1 2021/11/16 15:00:32 nia Exp $

PKGNAME=	${DISTNAME:S/plugins/plugins1/:S/-bad/-openh264/}
CATEGORIES=	multimedia gnome

COMMENT=	Open source multimedia framework - H.264/MPEG-4 decoder plugin

GST_EXT_BUILD=	# defined
GST_PLUGINS+=	openh264

.include "../../multimedia/gst-plugins1-bad/Makefile.common"
.include "../../multimedia/openh264/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
