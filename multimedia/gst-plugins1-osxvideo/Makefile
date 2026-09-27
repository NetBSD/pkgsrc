# $NetBSD: Makefile,v 1.5 2026/09/27 11:37:50 tnn Exp $

PKGNAME=	${DISTNAME:S/plugins/plugins1/:S/-good/-osxvideo/}
PKGREVISION=	2
CATEGORIES=	multimedia gnome

COMMENT=	Open source multimedia framework - macOS video plugin

GST_PLUGINS+=	osxvideo

ONLY_FOR_PLATFORM=	Darwin-*-*

.include "../../multimedia/gst-plugins1-good/Makefile.common"
.include "../../mk/bsd.pkg.mk"
