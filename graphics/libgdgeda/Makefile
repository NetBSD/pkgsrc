# $NetBSD: Makefile,v 1.17 2004/02/14 04:43:48 dmcmahill Exp $
#

DISTNAME=		libgdgeda-2.0.15
PKGREVISION=		1
CATEGORIES=		graphics
MASTER_SITES=		ftp://ftp.geda.seul.org/pub/geda/devel/support/

MAINTAINER=		dmcmahill@NetBSD.org
HOMEPAGE=		http://www.geda.seul.org/
COMMENT=		Modified version of the gd packages for use with gEDA

PKG_INSTALLATION_TYPES=	overwrite pkgviews

DIST_SUBDIR=		${PKGNAME}

GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
USE_BUILDLINK3=		YES

LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

.include "../../graphics/png/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
