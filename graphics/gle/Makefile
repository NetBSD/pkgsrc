# $NetBSD: Makefile,v 1.18 2004/06/28 14:17:36 minskim Exp $
#

DISTNAME=	gle-3.1.0
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gle/}		\
		http://www.linas.org/gle/pub/			\
		http://metalab.unc.edu/pub/Linux/libs/X/	\
		ftp://tsx-11.mit.edu/pub/linux/sources/libs/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.linas.org/gle/
COMMENT=	GL subroutines for drawing tubing and extrusions

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		YES
USE_X11=		YES
GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES

.include "../../graphics/Mesa/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
