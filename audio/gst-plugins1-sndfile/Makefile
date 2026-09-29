# $NetBSD: Makefile,v 1.16 2026/09/29 06:03:48 wiz Exp $

PKGNAME=	${DISTNAME:S/plugins/plugins1/:S/-bad/-sndfile/}
PKGREVISION=	3
CATEGORIES=	audio gnome

COMMENT=	Open source multimedia framework - libsndfile plugin

GST_EXT_BUILD=	# defined
GST_PLUGINS+=	sndfile

.include "../../multimedia/gst-plugins1-bad/Makefile.common"
.include "../../audio/libsndfile/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
