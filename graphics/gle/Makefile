# $NetBSD: Makefile,v 1.4 2001/08/29 22:41:18 jlam Exp $
#

DISTNAME=		gle-3.0.3
CATEGORIES=		graphics
MASTER_SITES=		http://www.linas.org/gle/pub/			\
			http://metalab.unc.edu/pub/Linux/libs/X/	\
			ftp://tsx-11.mit.edu/pub/linux/sources/libs/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.linas.org/gle/
COMMENT=		GL subroutines for drawing tubing and extrusions

USE_X11BASE=		YES
USE_LIBTOOL=		YES
GNU_CONFIGURE=		YES
USE_BUILDLINK_ONLY=	YES

LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

.include "../../graphics/Mesa/buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
