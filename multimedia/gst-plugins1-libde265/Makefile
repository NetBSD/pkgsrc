# $NetBSD: Makefile,v 1.1 2021/11/15 22:08:42 wiz Exp $

PKGNAME=	${DISTNAME:S/plugins/plugins1/:S/-bad/-libde265/}
CATEGORIES=	multimedia gnome

COMMENT=	Open source multimedia framework - HEVC/H.265 decoder plugin

GST_EXT_BUILD=	# defined
GST_PLUGINS+=	libde265

.include "../../multimedia/gst-plugins1-bad/Makefile.common"
.include "../../multimedia/libde265/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
