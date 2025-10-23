# $NetBSD: Makefile,v 1.9 2025/10/23 20:35:45 wiz Exp $

PKGNAME=	${DISTNAME:S/plugins/plugins1/:S/-good/-flac/}
PKGREVISION=	1
CATEGORIES=	audio gnome

COMMENT=	Open source multimedia framework - FLAC plugin

GST_PLUGINS+=	flac

.include "../../multimedia/gst-plugins1-good/Makefile.common"
.include "../../audio/flac/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
