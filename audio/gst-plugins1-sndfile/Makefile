# $NetBSD: Makefile,v 1.7 2023/06/02 16:09:46 wiz Exp $

PKGNAME=	${DISTNAME:S/plugins/plugins1/:S/-bad/-sndfile/}
CATEGORIES=	audio gnome

COMMENT=	Open source multimedia framework - libsndfile plugin

GST_EXT_BUILD=	# defined
GST_PLUGINS+=	sndfile

.include "../../multimedia/gst-plugins1-bad/Makefile.common"
.include "../../audio/libsndfile/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
