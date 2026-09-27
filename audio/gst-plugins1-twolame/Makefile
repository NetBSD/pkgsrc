# $NetBSD: Makefile,v 1.20 2026/09/27 11:34:57 tnn Exp $

PKGNAME=	${DISTNAME:S/plugins/plugins1/:S/-good/-twolame/}
PKGREVISION=	2
CATEGORIES=	audio gnome

COMMENT=	Open source multimedia framework - MP2 encoder plugin

GST_PLUGINS+=	twolame

.include "../../multimedia/gst-plugins1-good/Makefile.common"
.include "../../audio/twolame/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
