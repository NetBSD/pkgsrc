# $NetBSD: Makefile,v 1.10 2004/10/03 00:14:56 tv Exp $
#

DISTNAME=		plotutils-2.4.1
PKGNAME=		${DISTNAME:C/-/-nox11-/}
PKGREVISION=	1
CATEGORIES=		devel graphics
MASTER_SITES=		${MASTER_SITE_GNU:=plotutils/}

MAINTAINER=		dmcmahill@NetBSD.org
HOMEPAGE=		http://www.gnu.org/software/plotutils/plotutils.html
COMMENT=		Programs and library for plotting scientific data

CONFLICTS+=		plotutils-[0-9]*

DISTINFO_FILE=		${.CURDIR}/../../graphics/plotutils/distinfo
PATCHDIR=		${.CURDIR}/../../graphics/plotutils/patches

USE_BUILDLINK3=		yes
USE_GCC_SHLIB=		yes
USE_LANGUAGES=		c c++

INFO_FILES=	plotutils.info

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-libplotter
CONFIGURE_ARGS+=	--without-x
OPSYSVARS+=		USE_GNU_TOOLS
USE_GNU_TOOLS.IRIX+=	awk

USE_LIBTOOL=		yes
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig ${WRKSRC}/libxmi/ltconfig

.include "../../graphics/png/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
