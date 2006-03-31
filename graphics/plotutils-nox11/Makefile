# $NetBSD: Makefile,v 1.15 2006/03/31 17:28:11 jlam Exp $
#

DISTNAME=		plotutils-2.4.1
PKGNAME=		${DISTNAME:C/-/-nox11-/}
PKGREVISION=		1
CATEGORIES=		devel graphics
MASTER_SITES=		${MASTER_SITE_GNU:=plotutils/}

MAINTAINER=		dmcmahill@NetBSD.org
HOMEPAGE=		http://www.gnu.org/software/plotutils/plotutils.html
COMMENT=		Programs and library for plotting scientific data

CONFLICTS+=		plotutils-[0-9]*

DISTINFO_FILE=		${.CURDIR}/../../graphics/plotutils/distinfo
PATCHDIR=		${.CURDIR}/../../graphics/plotutils/patches

USE_LANGUAGES=		c c++

INFO_FILES=	plotutils.info

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-libplotter
CONFIGURE_ARGS+=	--without-x

.include "../../graphics/png/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
