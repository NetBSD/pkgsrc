# $NetBSD: Makefile,v 1.10 2000/08/24 00:03:47 dmcmahill Exp $
#

DISTNAME=		plotutils-2.4.1
# "nb1" is added to distinguish libplotter enabled version and existent pkg.
# If you update the base source above 2.3, this hack will no longer needed.
#PKGNAME=		plotutils-2.3nb1
CATEGORIES=		devel graphics x11
MASTER_SITES=		${MASTER_SITE_GNU:=plotutils/}

MAINTAINER=		dmcmahill@netbsd.org
HOMEPAGE=		http://www.gnu.org/software/plotutils/plotutils.html

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-libplotter

USE_LIBTOOL=		yes
USE_X11BASE=		yes
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig ${WRKSRC}/libxmi/ltconfig

INFO_FILES=		plotutils.info

.include "../../mk/bsd.pkg.mk"
