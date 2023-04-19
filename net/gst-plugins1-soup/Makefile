# $NetBSD: Makefile,v 1.43 2023/04/19 08:11:06 adam Exp $

PKGNAME=	${DISTNAME:S/plugins/plugins1/:S/-good/-soup/}
PKGREVISION=	1
CATEGORIES=	net gnome

COMMENT=	Open source multimedia framework - HTML (soup) plugin

GST_PLUGINS+=	soup

.include "../../multimedia/gst-plugins1-good/Makefile.common"
.include "../../net/libsoup/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
