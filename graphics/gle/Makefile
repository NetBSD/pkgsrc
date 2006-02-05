# $NetBSD: Makefile,v 1.23 2006/02/05 23:09:31 joerg Exp $
#

DISTNAME=	gle-3.1.0
PKGREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gle/}		\
		http://www.linas.org/gle/pub/			\
		http://metalab.unc.edu/pub/Linux/libs/X/	\
		ftp://tsx-11.mit.edu/pub/linux/sources/libs/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.linas.org/gle/
COMMENT=	GL subroutines for drawing tubing and extrusions

PKG_INSTALLATION_TYPES=	overwrite pkgviews

GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
LIBS+=			-lXext

.include "../../graphics/Mesa/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
