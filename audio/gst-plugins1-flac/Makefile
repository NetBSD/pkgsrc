# $NetBSD: Makefile,v 1.7 2025/02/12 06:44:22 ryoon Exp $

PKGNAME=	${DISTNAME:S/plugins/plugins1/:S/-good/-flac/}
PKGREVISION=	1
CATEGORIES=	audio gnome

COMMENT=	Open source multimedia framework - FLAC plugin

GST_PLUGINS+=	flac

.include "../../multimedia/gst-plugins1-good/Makefile.common"
.include "../../audio/flac/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
