# $NetBSD: Makefile,v 1.8 2003/06/02 01:19:27 jschauma Exp $
#

DISTNAME=		gle-3.0.3
CATEGORIES=		graphics
MASTER_SITES=		http://www.linas.org/gle/pub/			\
			http://metalab.unc.edu/pub/Linux/libs/X/	\
			ftp://tsx-11.mit.edu/pub/linux/sources/libs/

MAINTAINER=		tech-pkg@netbsd.org
HOMEPAGE=		http://www.linas.org/gle/
COMMENT=		GL subroutines for drawing tubing and extrusions

USE_BUILDLINK2=		YES
USE_X11BASE=		YES
GNU_CONFIGURE=		YES

USE_LIBTOOL=		YES
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

.include "../../graphics/Mesa/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
