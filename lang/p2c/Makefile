# $NetBSD: Makefile,v 1.4 2002/09/23 09:37:50 jlam Exp $

DISTNAME=	p2c-1.20
WRKSRC=		${WRKDIR}/src
CATEGORIES=	lang
MASTER_SITES=	ftp://csvax.cs.caltech.edu/pub/
EXTRACT_SUFX=   .tar.Z

MAINTAINER=	jwise@netbsd.org
COMMENT=	Pascal to C compiler (translates Pascal to C)

USE_BUILDLINK2=	# defined
CFLAGS+=	-Dunix=1

.include "../../mk/bsd.pkg.mk"
