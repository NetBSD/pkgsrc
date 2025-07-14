# $NetBSD: Makefile,v 1.14 2025/07/14 16:05:49 wiz Exp $

PKGNAME=	${DISTNAME:S/plugins/plugins1/:S/-good/-twolame/}
CATEGORIES=	audio gnome

COMMENT=	Open source multimedia framework - MP2 encoder plugin

GST_PLUGINS+=	twolame

.include "../../multimedia/gst-plugins1-good/Makefile.common"
.include "../../audio/twolame/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
