# $NetBSD: Makefile,v 1.6 2004/01/20 12:19:17 agc Exp $

DISTNAME=	p2c-1.20
CATEGORIES=	lang
MASTER_SITES=	ftp://csvax.cs.caltech.edu/pub/
EXTRACT_SUFX=   .tar.Z

MAINTAINER=	jwise@NetBSD.org
COMMENT=	Pascal to C compiler (translates Pascal to C)

WRKSRC=		${WRKDIR}/src
USE_BUILDLINK2=	# defined
CFLAGS+=	-Dunix=1

.include "../../mk/bsd.pkg.mk"
