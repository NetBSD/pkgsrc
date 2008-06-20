# $NetBSD: Makefile,v 1.26 2008/06/20 01:09:22 joerg Exp $
#

DISTNAME=	gle-3.1.0
PKGREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gle/}		\
		http://www.linas.org/gle/pub/			\
		http://metalab.unc.edu/pub/Linux/libs/X/	\
		ftp://tsx-11.mit.edu/pub/linux/sources/libs/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.linas.org/gle/
COMMENT=	GL subroutines for drawing tubing and extrusions

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
LIBS+=			-lXext

.include "../../graphics/Mesa/buildlink3.mk"
.include "../../x11/libXi/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
