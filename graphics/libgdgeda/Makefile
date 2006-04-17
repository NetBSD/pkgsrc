# $NetBSD: Makefile,v 1.22 2006/04/17 13:46:00 wiz Exp $
#

DISTNAME=		libgdgeda-2.0.15
PKGREVISION=		3
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
