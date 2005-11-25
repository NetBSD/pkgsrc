# $NetBSD: Makefile,v 1.2 2005/11/25 21:23:14 wiz Exp $

DISTNAME=	libwpd-0.8.1
PKGREVISION=	1
CATEGORIES=	converters
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=libwpd/}

MAINTAINER=	reed@reedmedia.net
HOMEPAGE=	http://libwpd.sourceforge.net/
COMMENT=	Library for importing and exporting WordPerfect(tm) documents

GNU_CONFIGURE=	YES
USE_LIBTOOL=	YES
USE_TOOLS+=	gmake
PKGCONFIG_OVERRIDE+=	libwpd-0.8.pc.in libwpd-stream-0.8.pc.in

CONFIGURE_ARGS+=	--without-docs

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libgsf/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
