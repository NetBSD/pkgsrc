# $NetBSD: Makefile,v 1.21 2003/06/04 18:21:50 jschauma Exp $
#

DISTNAME=		plotutils-2.4.1
PKGREVISION=		1
CATEGORIES=		devel graphics x11
MASTER_SITES=		${MASTER_SITE_GNU:=plotutils/}

MAINTAINER=		dmcmahill@netbsd.org
HOMEPAGE=		http://www.gnu.org/software/plotutils/plotutils.html
COMMENT=		Programs and library for plotting scientific data

USE_BUILDLINK2=		yes
USE_GCC_SHLIB=		yes

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-libplotter

USE_LIBTOOL=		yes
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig ${WRKSRC}/libxmi/ltconfig

.include "../../graphics/png/buildlink2.mk"
.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"
