# $NetBSD: Makefile,v 1.7 2026/09/30 18:51:21 adam Exp $

PKGNAME=	${DISTNAME:S/plugins/plugins1/:S/-good/-osxaudio/}
CATEGORIES=	audio gnome

COMMENT=	Open source multimedia framework - macOS audio plugin

GST_PLUGINS+=	osxaudio

ONLY_FOR_PLATFORM=	Darwin-*-*

.include "../../multimedia/gst-plugins1-good/Makefile.common"
.include "../../mk/bsd.pkg.mk"
