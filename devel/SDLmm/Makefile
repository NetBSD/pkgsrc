# $NetBSD: Makefile,v 1.6 2004/05/07 01:14:47 xtraeme Exp $
#

DISTNAME=	SDLmm-0.1.8
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=sdlmm/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://sdlmm.sourceforge.net/
COMMENT=	C++ Wrapper for the Simple DirectMedia Layer

GNU_CONFIGURE=	YES
USE_BUILDLINK3=	YES
USE_LIBTOOL=	YES

.include "../../devel/SDL/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
