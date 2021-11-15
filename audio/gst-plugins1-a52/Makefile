# $NetBSD: Makefile,v 1.4 2021/11/15 22:01:15 wiz Exp $

PKGNAME=	${DISTNAME:S/plugins/plugins1/:S/-ugly/-a52/}
CATEGORIES=	audio gnome

COMMENT=	Open source multimedia framework - Dolby AC-3 audio plugin

GST_PLUGINS+=	a52dec

.include "../../multimedia/gst-plugins1-ugly/Makefile.common"
.include "../../audio/liba52/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
