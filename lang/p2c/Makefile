# $NetBSD: Makefile,v 1.7 2004/04/25 07:19:25 snj Exp $

DISTNAME=	p2c-1.20
CATEGORIES=	lang
MASTER_SITES=	ftp://csvax.cs.caltech.edu/pub/
EXTRACT_SUFX=   .tar.Z

MAINTAINER=	jwise@NetBSD.org
COMMENT=	Pascal to C compiler (translates Pascal to C)

WRKSRC=		${WRKDIR}/src
USE_BUILDLINK3=	yes
CFLAGS+=	-Dunix=1

.include "../../mk/bsd.pkg.mk"
