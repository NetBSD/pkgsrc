# $NetBSD: Makefile,v 1.16 2001/06/11 06:34:38 jlam Exp $
#

DISTNAME=		plotutils-2.4.1
CATEGORIES=		devel graphics x11
MASTER_SITES=		${MASTER_SITE_GNU:=plotutils/}

MAINTAINER=		dmcmahill@netbsd.org
HOMEPAGE=		http://www.gnu.org/software/plotutils/plotutils.html
COMMENT=		Programs and library for plotting scientific data

DEPENDS+=		png>=1.0.11:../../graphics/png

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-libplotter
# make sure configure finds png
CPPFLAGS+=		-I${LOCALBASE}/include

USE_LIBTOOL=		yes
USE_X11BASE=		yes
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig ${WRKSRC}/libxmi/ltconfig

INFO_FILES=		plotutils.info

.include "../../mk/bsd.pkg.mk"
