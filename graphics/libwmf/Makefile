# $NetBSD: Makefile,v 1.31 2002/09/11 11:19:56 wiz Exp $
#

DISTNAME=		libwmf-0.2.6
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
