# $NetBSD: Makefile,v 1.2 2001/06/18 21:20:36 jlam Exp $
#

DISTNAME=		gle-3.0.3
CATEGORIES=		graphics
MASTER_SITES=		http://www.linas.org/gle/pub/			\
			http://metalab.unc.edu/pub/Linux/libs/X/	\
			ftp://tsx-11.mit.edu/pub/linux/sources/libs/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.linas.org/gle/
COMMENT=		GL subroutines for drawing tubing and extrusions

#USE_MESA=		YES
USE_X11BASE=		YES
USE_LIBTOOL=		YES
GNU_CONFIGURE=		YES

LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

.include "../../graphics/Mesa/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
