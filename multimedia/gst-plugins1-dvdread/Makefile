# $NetBSD: Makefile,v 1.7 2024/03/05 14:45:48 wiz Exp $

PKGNAME=	${DISTNAME:S/plugins/plugins1/:S/-ugly/-dvdread/}
CATEGORIES=	multimedia gnome

COMMENT=	Open source multimedia framework - DVD plugin

GST_PLUGINS+=	dvdread
GST_PLUGINS+=	gpl

.include "../../multimedia/gst-plugins1-ugly/Makefile.common"
.include "../../multimedia/libdvdread/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
