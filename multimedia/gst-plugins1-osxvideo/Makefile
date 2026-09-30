# $NetBSD: Makefile,v 1.7 2026/09/30 18:51:18 adam Exp $

PKGNAME=	${DISTNAME:S/plugins/plugins1/:S/-good/-osxvideo/}
CATEGORIES=	multimedia gnome

COMMENT=	Open source multimedia framework - macOS video plugin

GST_PLUGINS+=	osxvideo

ONLY_FOR_PLATFORM=	Darwin-*-*

.include "../../multimedia/gst-plugins1-good/Makefile.common"
.include "../../mk/bsd.pkg.mk"
