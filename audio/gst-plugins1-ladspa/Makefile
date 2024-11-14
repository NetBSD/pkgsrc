# $NetBSD: Makefile,v 1.18 2024/11/14 22:18:41 wiz Exp $

PKGNAME=	${DISTNAME:S/plugins/plugins1/:S/-bad/-ladspa/}
PKGREVISION=	1
CATEGORIES=	audio gnome

COMMENT=	Open source multimedia framework - LADSPA support plugin

GST_EXT_BUILD=	# defined
GST_PLUGINS+=	ladspa

.include "../../multimedia/gst-plugins1-bad/Makefile.common"
.include "../../audio/ladspa/buildlink3.mk"
.include "../../textproc/liblrdf/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
