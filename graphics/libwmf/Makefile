# $NetBSD: Makefile,v 1.32 2002/11/15 17:50:24 wiz Exp $
#

DISTNAME=		libwmf-0.2.7
CATEGORIES=		graphics devel
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=wvware/}

MAINTAINER=		kei@netbsd.org
HOMEPAGE=		http://www.wvware.com/libwmf.html
COMMENT=		library for reading and converting WMF (Windows Meta Files), version 2

USE_BUILDLINK2=		YES
GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--includedir=${INCLUDEDIR}
CONFIGURE_ARGS+=	--with-docdir=${HTMLDIR}
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
