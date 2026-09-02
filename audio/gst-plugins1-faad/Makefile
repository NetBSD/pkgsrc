# $NetBSD: Makefile,v 1.10 2026/09/02 19:00:50 wiz Exp $

PKGNAME=	${DISTNAME:S/plugins/plugins1/:S/-bad/-faad/}
PKGREVISION=	1
CATEGORIES=	audio gnome

COMMENT=	Open source multimedia framework - AAC decoder plugin

GST_EXT_BUILD=	# defined
GST_PLUGINS+=	gpl
GST_PLUGINS+=	faad

.include "../../multimedia/gst-plugins1-bad/Makefile.common"
.include "../../audio/faad2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
