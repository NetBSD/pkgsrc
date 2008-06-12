# $NetBSD: Makefile,v 1.15 2008/06/12 02:14:21 joerg Exp $
#

DISTNAME=	SDLmm-0.1.8
PKGREVISION=	6
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=sdlmm/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://sdlmm.sourceforge.net/
COMMENT=	C++ Wrapper for the Simple DirectMedia Layer

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	YES
USE_LANGUAGES=	c c++
USE_LIBTOOL=	YES

.include "../../devel/SDL/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
