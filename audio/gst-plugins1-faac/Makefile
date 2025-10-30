# $NetBSD: Makefile,v 1.6 2025/10/30 15:35:39 adam Exp $

PKGNAME=	${DISTNAME:S/plugins/plugins1/:S/-bad/-faac/}
CATEGORIES=	audio gnome

COMMENT=	Open source multimedia framework - AAC encoder plugin

GST_EXT_BUILD=	# defined
GST_PLUGINS+=	faac

.include "../../multimedia/gst-plugins1-bad/Makefile.common"
.include "../../audio/faac/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
