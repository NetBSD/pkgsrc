# $NetBSD: Makefile,v 1.5 2025/10/23 20:35:47 wiz Exp $

PKGNAME=	${DISTNAME:S/plugins/plugins1/:S/-good/-wavpack/}
PKGREVISION=	1
CATEGORIES=	audio gnome

COMMENT=	Open source multimedia framework - WavPack plugin

GST_PLUGINS+=	wavpack

.include "../../multimedia/gst-plugins1-good/Makefile.common"
.include "../../audio/wavpack/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
