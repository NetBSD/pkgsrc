# $NetBSD: Makefile,v 1.21 2005/12/05 20:50:21 rillig Exp $
#

DISTNAME=		libgdgeda-2.0.15
PKGREVISION=		2
CATEGORIES=		graphics
MASTER_SITES=		ftp://ftp.geda.seul.org/pub/geda/devel/support/

MAINTAINER=		dmcmahill@NetBSD.org
HOMEPAGE=		http://www.geda.seul.org/
COMMENT=		Modified version of the gd packages for use with gEDA

PKG_INSTALLATION_TYPES=	overwrite pkgviews

DIST_SUBDIR=		${PKGNAME_NOREV}nb2

GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES

.include "../../graphics/png/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
