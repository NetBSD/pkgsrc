# $NetBSD: Makefile,v 1.6 2003/09/19 10:14:11 wiz Exp $
#

DISTNAME=		plotutils-2.4.1
PKGNAME=		${DISTNAME:C/-/-nox11-/}
CATEGORIES=		devel graphics
MASTER_SITES=		${MASTER_SITE_GNU:=plotutils/}

MAINTAINER=		dmcmahill@NetBSD.org
HOMEPAGE=		http://www.gnu.org/software/plotutils/plotutils.html
COMMENT=		Programs and library for plotting scientific data

CONFLICTS+=		plotutils-[0-9]*

DISTINFO_FILE=		${.CURDIR}/../../graphics/plotutils/distinfo
PATCHDIR=		${.CURDIR}/../../graphics/plotutils/patches

USE_BUILDLINK2=		yes
USE_GCC_SHLIB=		yes

INFO_FILES=	plotutils.info

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-libplotter
CONFIGURE_ARGS+=	--without-x

USE_LIBTOOL=		yes
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig ${WRKSRC}/libxmi/ltconfig

.include "../../graphics/png/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
