# $NetBSD: Makefile,v 1.3.2.1 2002/06/21 23:05:40 jlam Exp $

DISTNAME=	mhash-0.8.9
CATEGORIES=	security devel
MASTER_SITES=	http://mhash.sourceforge.net/dl/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://mhash.sourceforge.net/
COMMENT=	hash algorithms library

USE_BUILDLINK2=		YES
GNU_CONFIGURE=		YES

USE_LIBTOOL=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

.include "../../mk/bsd.pkg.mk"
