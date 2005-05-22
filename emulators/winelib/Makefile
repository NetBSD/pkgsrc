# $NetBSD: Makefile,v 1.8 2005/05/22 20:07:59 jlam Exp $
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
USE_TOOLS+=		gmake
CONFIGURE_ARGS+=	--with-wine=${BUILDLINK_PREFIX.wine}

.include "../../emulators/wine/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
