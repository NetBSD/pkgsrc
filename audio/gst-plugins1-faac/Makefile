# $NetBSD: Makefile,v 1.7 2026/09/02 19:00:50 wiz Exp $

PKGNAME=	${DISTNAME:S/plugins/plugins1/:S/-bad/-faac/}
PKGREVISION=	1
CATEGORIES=	audio gnome

COMMENT=	Open source multimedia framework - AAC encoder plugin

GST_EXT_BUILD=	# defined
GST_PLUGINS+=	faac

.include "../../multimedia/gst-plugins1-bad/Makefile.common"
.include "../../audio/faac/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
