# $NetBSD: Makefile,v 1.6 2025/10/30 15:35:41 adam Exp $

PKGNAME=	${DISTNAME:S/plugins/plugins1/:S/-good/-speex/}
CATEGORIES=	audio gnome

COMMENT=	Open source multimedia framework - Speex plugin

GST_PLUGINS+=	speex

.include "../../multimedia/gst-plugins1-good/Makefile.common"
.include "../../audio/speex/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
