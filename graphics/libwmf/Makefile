# $NetBSD: Makefile,v 1.28 2001/12/10 13:56:42 taca Exp $
#

DISTNAME=		libwmf-0.2.2
CATEGORIES=		graphics devel
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=wvware/}

MAINTAINER=		kei@netbsd.org
HOMEPAGE=		http://www.wvware.com/libwmf.html
COMMENT=		library for reading and converting WMF (Windows Meta Files), version 2

USE_BUILDLINK_ONLY=	YES
GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--enable-magick
CONFIGURE_ARGS+=	--includedir=${INCLUDEDIR}
CONFIGURE_ARGS+=	--with-docdir=${HTMLDIR}
USE_X11=		YES
USE_LIBTOOL=		YES
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

INCLUDEDIR=		${PREFIX}/include/libwmf
HTMLDIR=		${PREFIX}/share/doc/html/libwmf

.include "../../graphics/freetype2/buildlink.mk"
.include "../../graphics/png/buildlink.mk"
.include "../../graphics/xpm/buildlink.mk"
.include "../../textproc/libxml2/buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
