# $NetBSD: Makefile,v 1.24 2003/06/06 14:39:06 jschauma Exp $
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

.include "../../mk/bsd.prefs.mk"

# this package works with and without X11, but if X11 is present, we need the
# necessary compile and ld flags
.if exists(${X11BASE})
PKGNAME=		${DISTNAME:C/-/-x11-/}
CONFLICTS+=		${DISTNAME:C/-[0-9].*//}
USE_X11=                YES
.else
CONFLICTS+=		${DISTNAME:C/-[0-9].*/-x11/}
.endif

.include "../../graphics/png/buildlink2.mk"
.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"
