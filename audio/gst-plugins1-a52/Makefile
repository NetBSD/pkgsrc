# $NetBSD: Makefile,v 1.10 2026/09/02 19:00:50 wiz Exp $

PKGNAME=	${DISTNAME:S/plugins/plugins1/:S/-ugly/-a52/}
PKGREVISION=	1
CATEGORIES=	audio gnome

COMMENT=	Open source multimedia framework - Dolby AC-3 audio plugin

GST_PLUGINS+=	a52dec gpl

.include "../../multimedia/gst-plugins1-ugly/Makefile.common"
.include "../../audio/liba52/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
