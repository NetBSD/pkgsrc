# $NetBSD: Makefile,v 1.5 2003/11/03 18:27:54 gavan Exp $
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
USE_GCC_SHLIB=		yes

.include "../../mk/bsd.pkg.mk"
