# $NetBSD: Makefile,v 1.11 2023/05/06 19:08:59 ryoon Exp $

PKGNAME=	${DISTNAME:S/plugins/plugins1/:S/-good/-twolame/}
PKGREVISION=	1
CATEGORIES=	audio gnome

COMMENT=	Open source multimedia framework - MP2 encoder plugin

GST_PLUGINS+=	twolame

.include "../../multimedia/gst-plugins1-good/Makefile.common"
.include "../../audio/twolame/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
