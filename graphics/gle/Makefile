# $NetBSD: Makefile,v 1.28 2012/10/06 14:10:55 asau Exp $
#

DISTNAME=	gle-3.1.0
PKGREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gle/}		\
		http://www.linas.org/gle/pub/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.linas.org/gle/
COMMENT=	GL subroutines for drawing tubing and extrusions

PKG_INSTALLATION_TYPES=	overwrite pkgviews

GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
LIBS+=			-lXext

.include "../../graphics/Mesa/buildlink3.mk"
.include "../../x11/libXi/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
