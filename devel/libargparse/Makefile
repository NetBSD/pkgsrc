# $NetBSD: Makefile,v 1.6 2004/02/02 13:02:49 jlam Exp $
#

DISTNAME=		libargparse-0.1.0000
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=aqsis/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.aqsis.org/
COMMENT=		Argument parsing library in C++

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

USE_BUILDLINK2=		yes
USE_LANGUAGES=		c c++

.include "../../mk/bsd.pkg.mk"
