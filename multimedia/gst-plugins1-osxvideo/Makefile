# $NetBSD: Makefile,v 1.1 2022/09/24 20:22:49 adam Exp $

PKGNAME=	${DISTNAME:S/plugins/plugins1/:S/-good/-osxvideo/}
CATEGORIES=	multimedia gnome

COMMENT=	Open source multimedia framework - macOS video plugin

GST_PLUGINS+=	osxvideo

ONLY_FOR_PLATFORM=	Darwin-*-*

.include "../../multimedia/gst-plugins1-good/Makefile.common"
.include "../../mk/bsd.pkg.mk"
