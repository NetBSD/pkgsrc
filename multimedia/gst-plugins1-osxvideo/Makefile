# $NetBSD: Makefile,v 1.3 2025/10/30 15:35:37 adam Exp $

PKGNAME=	${DISTNAME:S/plugins/plugins1/:S/-good/-osxvideo/}
CATEGORIES=	multimedia gnome

COMMENT=	Open source multimedia framework - macOS video plugin

GST_PLUGINS+=	osxvideo

ONLY_FOR_PLATFORM=	Darwin-*-*

.include "../../multimedia/gst-plugins1-good/Makefile.common"
.include "../../mk/bsd.pkg.mk"
