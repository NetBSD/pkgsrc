# $NetBSD: Makefile,v 1.7 2026/09/02 19:00:52 wiz Exp $

PKGNAME=	${DISTNAME:S/plugins/plugins1/:S/-good/-speex/}
PKGREVISION=	1
CATEGORIES=	audio gnome

COMMENT=	Open source multimedia framework - Speex plugin

GST_PLUGINS+=	speex

.include "../../multimedia/gst-plugins1-good/Makefile.common"
.include "../../audio/speex/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
