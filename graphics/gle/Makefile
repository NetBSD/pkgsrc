# $NetBSD: Makefile,v 1.13 2004/02/01 10:04:12 jlam Exp $
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

USE_BUILDLINK3=		YES
USE_X11=		YES
GNU_CONFIGURE=		YES

CONFIG_GUESS_OVERRIDE+=	${WRKSRC}/config.guess
CONFIG_SUB_OVERRIDE+=	${WRKSRC}/config.sub

USE_LIBTOOL=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

.include "../../graphics/Mesa/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
