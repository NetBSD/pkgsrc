# $NetBSD: Makefile,v 1.10 2026/09/30 18:51:22 adam Exp $

PKGNAME=	${DISTNAME:S/plugins/plugins1/:S/-good/-wavpack/}
CATEGORIES=	audio gnome

COMMENT=	Open source multimedia framework - WavPack plugin

GST_PLUGINS+=	wavpack

.include "../../multimedia/gst-plugins1-good/Makefile.common"
.include "../../audio/wavpack/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
