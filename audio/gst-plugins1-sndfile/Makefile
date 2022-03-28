# $NetBSD: Makefile,v 1.2 2022/03/28 10:43:33 tnn Exp $

PKGNAME=	${DISTNAME:S/plugins/plugins1/:S/-bad/-sndfile/}
PKGREVISION=	1
CATEGORIES=	audio gnome

COMMENT=	Open source multimedia framework - libsndfile plugin

GST_EXT_BUILD=	# defined
GST_PLUGINS+=	sndfile

.include "../../multimedia/gst-plugins1-bad/Makefile.common"
.include "../../audio/libsndfile/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
