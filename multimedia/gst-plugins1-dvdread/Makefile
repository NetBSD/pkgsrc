# $NetBSD: Makefile,v 1.12 2026/09/29 06:06:47 wiz Exp $

PKGNAME=	${DISTNAME:S/plugins/plugins1/:S/-ugly/-dvdread/}
PKGREVISION=	3
CATEGORIES=	multimedia gnome

COMMENT=	Open source multimedia framework - DVD plugin

GST_PLUGINS+=	dvdread
GST_PLUGINS+=	gpl

.include "../../multimedia/gst-plugins1-ugly/Makefile.common"
.include "../../multimedia/libdvdread/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
