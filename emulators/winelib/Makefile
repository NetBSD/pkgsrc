# $NetBSD: Makefile,v 1.7 2005/04/11 21:45:46 tv Exp $
#

DISTNAME=	winelib-0.3
PKGREVISION=	1
CATEGORIES=	emulators
MASTER_SITES=	http://mono2.ximian.com/archive/1.0/

MAINTAINER=	recht@NetBSD.org
HOMEPAGE=	http://www.mono-project.com/
COMMENT=	Library to bind Wine as shared library

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_GNU_TOOLS+=		make
CONFIGURE_ARGS+=	--with-wine=${BUILDLINK_PREFIX.wine}

.include "../../emulators/wine/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
