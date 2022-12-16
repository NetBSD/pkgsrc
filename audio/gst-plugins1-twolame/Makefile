# $NetBSD: Makefile,v 1.10 2022/12/16 21:08:10 adam Exp $

PKGNAME=	${DISTNAME:S/plugins/plugins1/:S/-good/-twolame/}
CATEGORIES=	audio gnome

COMMENT=	Open source multimedia framework - MP2 encoder plugin

GST_PLUGINS+=	twolame

.include "../../multimedia/gst-plugins1-good/Makefile.common"
.include "../../audio/twolame/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
