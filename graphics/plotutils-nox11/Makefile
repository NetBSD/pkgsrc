# $NetBSD: Makefile,v 1.19 2008/06/12 02:14:32 joerg Exp $
#

DISTNAME=		plotutils-2.4.1
PKGNAME=		${DISTNAME:C/-/-nox11-/}
PKGREVISION=		2
CATEGORIES=		devel graphics
MASTER_SITES=		${MASTER_SITE_GNU:=plotutils/}

MAINTAINER=		dmcmahill@NetBSD.org
HOMEPAGE=		http://www.gnu.org/software/plotutils/plotutils.html
COMMENT=		Programs and library for plotting scientific data

PKG_DESTDIR_SUPPORT=	user-destdir

CONFLICTS+=		plotutils-[0-9]*

DISTINFO_FILE=		${.CURDIR}/../../graphics/plotutils/distinfo
PATCHDIR=		${.CURDIR}/../../graphics/plotutils/patches

USE_LANGUAGES=		c c++
USE_TOOLS+=		lex

INFO_FILES=		# PLIST
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-libplotter
CONFIGURE_ARGS+=	--without-x

.include "../../graphics/png/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
