# $NetBSD: Makefile,v 1.8 2003/07/17 22:52:59 grant Exp $

DISTNAME=	mhash-0.8.17
CATEGORIES=	security devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=mhash/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://mhash.sourceforge.net/
COMMENT=	hash algorithms library

USE_BUILDLINK2=		YES
GNU_CONFIGURE=		YES

USE_LIBTOOL=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

.include "../../mk/bsd.pkg.mk"
