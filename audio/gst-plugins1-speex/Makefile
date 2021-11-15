# $NetBSD: Makefile,v 1.4 2021/11/15 22:01:17 wiz Exp $

PKGNAME=	${DISTNAME:S/plugins/plugins1/:S/-good/-speex/}
CATEGORIES=	audio gnome

COMMENT=	Open source multimedia framework - Speex plugin

GST_PLUGINS+=	speex

.include "../../multimedia/gst-plugins1-good/Makefile.common"
.include "../../audio/speex/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
