# $NetBSD: Makefile,v 1.12 2000/08/25 23:47:13 dmcmahill Exp $
#

DISTNAME=		plotutils-2.4.1
CATEGORIES=		devel graphics x11
MASTER_SITES=		${MASTER_SITE_GNU:=plotutils/}

MAINTAINER=		dmcmahill@netbsd.org
HOMEPAGE=		http://www.gnu.org/software/plotutils/plotutils.html

DEPENDS+=		png>=1.0.6:../../graphics/png

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-libplotter
# make sure configure finds png
CPPFLAGS+=		-I${LOCALBASE}/include
CONFIGURE_ENV+=		CFLAGS="${CFLAGS}" CPPFLAGS="${CPPFLAGS}"

USE_LIBTOOL=		yes
USE_X11BASE=		yes
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig ${WRKSRC}/libxmi/ltconfig

INFO_FILES=		plotutils.info

.include "../../mk/bsd.pkg.mk"
