# $NetBSD: Makefile,v 1.5 2026/09/27 11:34:56 tnn Exp $

PKGNAME=	${DISTNAME:S/plugins/plugins1/:S/-good/-osxaudio/}
PKGREVISION=	2
CATEGORIES=	audio gnome

COMMENT=	Open source multimedia framework - macOS audio plugin

GST_PLUGINS+=	osxaudio

ONLY_FOR_PLATFORM=	Darwin-*-*

.include "../../multimedia/gst-plugins1-good/Makefile.common"
.include "../../mk/bsd.pkg.mk"
