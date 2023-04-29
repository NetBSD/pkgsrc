# $NetBSD: Makefile,v 1.8 2023/04/29 07:12:13 wiz Exp $

PKGNAME=	${DISTNAME:S/plugins/plugins1/:S/-bad/-ladspa/}
CATEGORIES=	audio gnome

COMMENT=	Open source multimedia framework - LADSPA support plugin

GST_EXT_BUILD=	# defined
GST_PLUGINS+=	ladspa

.include "../../multimedia/gst-plugins1-bad/Makefile.common"
.include "../../audio/ladspa/buildlink3.mk"
.include "../../textproc/liblrdf/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
