# $NetBSD: Makefile,v 1.25 2003/06/07 17:39:24 jschauma Exp $
#

DISTNAME=		plotutils-2.4.1
PKGREVISION=		2
CATEGORIES=		devel graphics x11
MASTER_SITES=		${MASTER_SITE_GNU:=plotutils/}

MAINTAINER=		dmcmahill@netbsd.org
HOMEPAGE=		http://www.gnu.org/software/plotutils/plotutils.html
COMMENT=		Programs and library for plotting scientific data

CONFLICTS+=		${DISTNAME:C/-[0-9].*/-nox11/}

USE_BUILDLINK2=		YES
USE_GCC_SHLIB=		YES
USE_X11=		YES

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--enable-libplotter

USE_LIBTOOL=		YES
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig ${WRKSRC}/libxmi/ltconfig

.include "../../graphics/png/buildlink2.mk"
.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"
