# $NetBSD: Makefile,v 1.6 2006/02/05 23:08:29 joerg Exp $

DISTNAME=	libwpd-0.8.1
PKGREVISION=	4
CATEGORIES=	converters
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=libwpd/}

MAINTAINER=	reed@reedmedia.net
HOMEPAGE=	http://libwpd.sourceforge.net/
COMMENT=	Library for importing and exporting WordPerfect(tm) documents

GNU_CONFIGURE=	YES
USE_LIBTOOL=	YES
USE_TOOLS+=	gmake pkg-config
PKGCONFIG_OVERRIDE+=	libwpd-0.8.pc.in libwpd-stream-0.8.pc.in

CONFIGURE_ARGS+=	--without-docs

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libgsf/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
