# $NetBSD: Makefile,v 1.1.1.1 2004/04/04 16:52:40 recht Exp $
#

DISTNAME=	winelib-0.1
CATEGORIES=	emulators
MASTER_SITES=	http://www.go-mono.com/archive/

MAINTAINER=	recht@NetBSD.com
HOMEPAGE=	http://www.go-mono.com/
COMMENT=	Library to bind Wine as shared library

USE_BUILDLINK3=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_GNU_TOOLS+=		make
CONFIGURE_ARGS+=	--with-wine=${BUILDLINK_PREFIX.wine}

.include "../../emulators/wine/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
