# $NetBSD: Makefile,v 1.9 2026/09/29 06:03:46 wiz Exp $

PKGNAME=	${DISTNAME:S/plugins/plugins1/:S/-bad/-faac/}
PKGREVISION=	3
CATEGORIES=	audio gnome

COMMENT=	Open source multimedia framework - AAC encoder plugin

GST_EXT_BUILD=	# defined
GST_PLUGINS+=	faac

.include "../../multimedia/gst-plugins1-bad/Makefile.common"
.include "../../audio/faac/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
