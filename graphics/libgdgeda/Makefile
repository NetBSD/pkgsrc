# $NetBSD: Makefile,v 1.16 2003/11/03 10:51:46 agc Exp $
#

DISTNAME=		libgdgeda-2.0.15
CATEGORIES=		graphics
PKGREVISION=		1
MASTER_SITES=		ftp://ftp.geda.seul.org/pub/geda/devel/support/

MAINTAINER=		dmcmahill@NetBSD.org
HOMEPAGE=		http://www.geda.seul.org/
COMMENT=		Modified version of the gd packages for use with gEDA

DIST_SUBDIR=		${PKGNAME}

GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
USE_BUILDLINK2=		YES

LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

.include "../../graphics/png/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
