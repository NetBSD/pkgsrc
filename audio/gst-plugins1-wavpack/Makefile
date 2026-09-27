# $NetBSD: Makefile,v 1.8 2026/09/27 11:34:57 tnn Exp $

PKGNAME=	${DISTNAME:S/plugins/plugins1/:S/-good/-wavpack/}
PKGREVISION=	2
CATEGORIES=	audio gnome

COMMENT=	Open source multimedia framework - WavPack plugin

GST_PLUGINS+=	wavpack

.include "../../multimedia/gst-plugins1-good/Makefile.common"
.include "../../audio/wavpack/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
