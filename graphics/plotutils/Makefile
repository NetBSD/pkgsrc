# $NetBSD: Makefile,v 1.28 2003/08/09 10:53:29 seb Exp $
#

DISTNAME=		plotutils-2.4.1
PKGREVISION=		2
CATEGORIES=		devel graphics x11
MASTER_SITES=		${MASTER_SITE_GNU:=plotutils/}

MAINTAINER=		dmcmahill@NetBSD.org
HOMEPAGE=		http://www.gnu.org/software/plotutils/plotutils.html
COMMENT=		Programs and library for plotting scientific data

CONFLICTS+=		plotutils-nox11-[0-9]*

USE_BUILDLINK2=		YES
USE_GCC_SHLIB=		YES
USE_X11=		YES

INFO_FILES=	plotutils.info

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--enable-libplotter

USE_LIBTOOL=		YES
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig ${WRKSRC}/libxmi/ltconfig

.include "../../graphics/png/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
