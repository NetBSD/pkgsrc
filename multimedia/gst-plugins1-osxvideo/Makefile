# $NetBSD: Makefile,v 1.6 2026/09/29 06:06:48 wiz Exp $

PKGNAME=	${DISTNAME:S/plugins/plugins1/:S/-good/-osxvideo/}
PKGREVISION=	3
CATEGORIES=	multimedia gnome

COMMENT=	Open source multimedia framework - macOS video plugin

GST_PLUGINS+=	osxvideo

ONLY_FOR_PLATFORM=	Darwin-*-*

.include "../../multimedia/gst-plugins1-good/Makefile.common"
.include "../../mk/bsd.pkg.mk"
