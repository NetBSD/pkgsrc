# $NetBSD: Makefile,v 1.10 2026/09/02 19:03:41 wiz Exp $

PKGNAME=	${DISTNAME:S/plugins/plugins1/:S/-ugly/-dvdread/}
PKGREVISION=	1
CATEGORIES=	multimedia gnome

COMMENT=	Open source multimedia framework - DVD plugin

GST_PLUGINS+=	dvdread
GST_PLUGINS+=	gpl

.include "../../multimedia/gst-plugins1-ugly/Makefile.common"
.include "../../multimedia/libdvdread/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
