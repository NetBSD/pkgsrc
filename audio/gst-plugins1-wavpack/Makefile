# $NetBSD: Makefile,v 1.7 2026/09/02 19:00:53 wiz Exp $

PKGNAME=	${DISTNAME:S/plugins/plugins1/:S/-good/-wavpack/}
PKGREVISION=	1
CATEGORIES=	audio gnome

COMMENT=	Open source multimedia framework - WavPack plugin

GST_PLUGINS+=	wavpack

.include "../../multimedia/gst-plugins1-good/Makefile.common"
.include "../../audio/wavpack/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
