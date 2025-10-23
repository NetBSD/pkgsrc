# $NetBSD: Makefile,v 1.2 2025/10/23 20:35:46 wiz Exp $

PKGNAME=	${DISTNAME:S/plugins/plugins1/:S/-good/-osxaudio/}
PKGREVISION=	1
CATEGORIES=	audio gnome

COMMENT=	Open source multimedia framework - macOS audio plugin

GST_PLUGINS+=	osxaudio

ONLY_FOR_PLATFORM=	Darwin-*-*

.include "../../multimedia/gst-plugins1-good/Makefile.common"
.include "../../mk/bsd.pkg.mk"
