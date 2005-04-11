# $NetBSD: Makefile,v 1.20 2005/04/11 21:46:05 tv Exp $
#

DISTNAME=		libgdgeda-2.0.15
PKGREVISION=		2
CATEGORIES=		graphics
MASTER_SITES=		ftp://ftp.geda.seul.org/pub/geda/devel/support/

MAINTAINER=		dmcmahill@NetBSD.org
HOMEPAGE=		http://www.geda.seul.org/
COMMENT=		Modified version of the gd packages for use with gEDA

PKG_INSTALLATION_TYPES=	overwrite pkgviews

DIST_SUBDIR=		${PKGNAME}

GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES

.include "../../graphics/png/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
