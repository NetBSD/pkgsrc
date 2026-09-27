# $NetBSD: Makefile,v 1.12 2026/09/27 11:34:54 tnn Exp $

PKGNAME=	${DISTNAME:S/plugins/plugins1/:S/-good/-flac/}
PKGREVISION=	2
CATEGORIES=	audio gnome

COMMENT=	Open source multimedia framework - FLAC plugin

GST_PLUGINS+=	flac

.include "../../multimedia/gst-plugins1-good/Makefile.common"
.include "../../audio/flac/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
