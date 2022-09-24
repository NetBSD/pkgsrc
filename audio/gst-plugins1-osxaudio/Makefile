# $NetBSD: Makefile,v 1.1 2022/09/24 20:21:25 adam Exp $

PKGNAME=	${DISTNAME:S/plugins/plugins1/:S/-good/-osxaudio/}
CATEGORIES=	audio gnome

COMMENT=	Open source multimedia framework - macOS audio plugin

GST_PLUGINS+=	osxaudio

ONLY_FOR_PLATFORM=	Darwin-*-*

.include "../../multimedia/gst-plugins1-good/Makefile.common"
.include "../../mk/bsd.pkg.mk"
