# $NetBSD: Makefile,v 1.40 2022/12/16 21:08:11 adam Exp $

PKGNAME=	${DISTNAME:S/plugins/plugins1/:S/-good/-soup/}
CATEGORIES=	net gnome

COMMENT=	Open source multimedia framework - HTML (soup) plugin

GST_PLUGINS+=	soup

.include "../../multimedia/gst-plugins1-good/Makefile.common"
.include "../../net/libsoup/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
