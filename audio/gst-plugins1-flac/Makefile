# $NetBSD: Makefile,v 1.13 2026/09/29 06:03:46 wiz Exp $

PKGNAME=	${DISTNAME:S/plugins/plugins1/:S/-good/-flac/}
PKGREVISION=	3
CATEGORIES=	audio gnome

COMMENT=	Open source multimedia framework - FLAC plugin

GST_PLUGINS+=	flac

.include "../../multimedia/gst-plugins1-good/Makefile.common"
.include "../../audio/flac/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
