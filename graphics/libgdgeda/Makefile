# $NetBSD: Makefile,v 1.15 2003/10/29 23:15:27 dmcmahill Exp $
#

DISTNAME=		libgdgeda-2.0.15
CATEGORIES=		graphics
MASTER_SITES=		ftp://ftp.geda.seul.org/pub/geda/devel/support/

MAINTAINER=		dmcmahill@NetBSD.org
HOMEPAGE=		http://www.geda.seul.org/
COMMENT=		Modified version of the gd packages for use with gEDA

GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
USE_BUILDLINK2=		YES

LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

.include "../../graphics/png/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
