# $NetBSD: Makefile,v 1.1 2003/06/07 17:39:24 jschauma Exp $
#

DISTNAME=		plotutils-2.4.1
PKGNAME=		${DISTNAME:C/-/-nox11-/}
CATEGORIES=		devel graphics
MASTER_SITES=		${MASTER_SITE_GNU:=plotutils/}

MAINTAINER=		dmcmahill@netbsd.org
HOMEPAGE=		http://www.gnu.org/software/plotutils/plotutils.html
COMMENT=		Programs and library for plotting scientific data

CONFLICTS+=		${DISTNAME:C/-[0-9].*//}

USE_BUILDLINK2=		yes
USE_GCC_SHLIB=		yes

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-libplotter
CONFIGURE_ARGS+=	--without-x

USE_LIBTOOL=		yes
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig ${WRKSRC}/libxmi/ltconfig

.include "../../graphics/png/buildlink2.mk"
.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"
