# $NetBSD: Makefile,v 1.40 2003/09/09 16:23:49 jmmv Exp $
#

DISTNAME=		libwmf-0.2.8
PKGREVISION=		2
CATEGORIES=		graphics devel
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=wvware/}

MAINTAINER=		kei@NetBSD.org
HOMEPAGE=		http://www.wvware.com/libwmf.html
COMMENT=		Library for reading and converting WMF (Windows Meta Files), version 2

USE_BUILDLINK2=		YES
GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--disable-gd
CONFIGURE_ARGS+=	--includedir=${INCLUDEDIR}
CONFIGURE_ARGS+=	--with-docdir=${HTMLDIR}
CONFIGURE_ARGS+=	--without-sys-gd
USE_X11=		YES
USE_LIBTOOL=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

INCLUDEDIR=		${PREFIX}/include/libwmf
HTMLDIR=		${PREFIX}/share/doc/html/libwmf

.include "../../graphics/freetype2/buildlink2.mk"
.include "../../graphics/png/buildlink2.mk"
.include "../../graphics/xpm/buildlink2.mk"
.include "../../textproc/libxml2/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
