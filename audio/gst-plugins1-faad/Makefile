# $NetBSD: Makefile,v 1.4 2021/11/15 22:01:16 wiz Exp $

PKGNAME=	${DISTNAME:S/plugins/plugins1/:S/-bad/-faad/}
CATEGORIES=	audio gnome

COMMENT=	Open source multimedia framework - AAC decoder plugin

GST_EXT_BUILD=	# defined
GST_PLUGINS+=	faad

.include "../../multimedia/gst-plugins1-bad/Makefile.common"
.include "../../audio/faad2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
