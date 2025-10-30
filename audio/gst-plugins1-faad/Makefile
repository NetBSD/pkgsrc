# $NetBSD: Makefile,v 1.9 2025/10/30 15:35:39 adam Exp $

PKGNAME=	${DISTNAME:S/plugins/plugins1/:S/-bad/-faad/}
CATEGORIES=	audio gnome

COMMENT=	Open source multimedia framework - AAC decoder plugin

GST_EXT_BUILD=	# defined
GST_PLUGINS+=	gpl
GST_PLUGINS+=	faad

.include "../../multimedia/gst-plugins1-bad/Makefile.common"
.include "../../audio/faad2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
