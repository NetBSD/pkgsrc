# $NetBSD: Makefile,v 1.55 2025/04/19 07:58:10 wiz Exp $

PKGNAME=	${DISTNAME:S/plugins/plugins1/:S/-good/-soup/}
PKGREVISION=	2
CATEGORIES=	net gnome

COMMENT=	Open source multimedia framework - HTML (soup) plugin

GST_PLUGINS+=	soup

.include "../../multimedia/gst-plugins1-good/Makefile.common"
.include "../../net/libsoup/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
