# $NetBSD: Makefile,v 1.5 2004/10/03 00:14:41 tv Exp $
#

DISTNAME=	winelib-0.3
PKGREVISION=	1
CATEGORIES=	emulators
MASTER_SITES=	http://mono2.ximian.com/archive/1.0/

MAINTAINER=	recht@NetBSD.com
HOMEPAGE=	http://www.mono-project.com/
COMMENT=	Library to bind Wine as shared library

USE_BUILDLINK3=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_GNU_TOOLS+=		make
CONFIGURE_ARGS+=	--with-wine=${BUILDLINK_PREFIX.wine}

.include "../../emulators/wine/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
