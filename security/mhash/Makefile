# $NetBSD: Makefile,v 1.6 2002/11/13 22:53:42 jschauma Exp $

DISTNAME=	mhash-0.8.17
CATEGORIES=	security devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=mhash/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://mhash.sourceforge.net/
COMMENT=	hash algorithms library

USE_BUILDLINK2=		YES
GNU_CONFIGURE=		YES

USE_LIBTOOL=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

.include "../../mk/bsd.pkg.mk"
