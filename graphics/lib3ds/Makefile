# $NetBSD: Makefile,v 1.7 2004/04/24 20:51:46 snj Exp $
#

DISTNAME=	lib3ds-1.2.0
PKGREVISION=	2
CATEGORIES=	graphics devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=lib3ds/}

MAINTAINER=	rh@NetBSD.org
HOMEPAGE=	http://lib3ds.sourceforge.net/
COMMENT=	3D Studio File Format Library

GNU_CONFIGURE=	YES
USE_BUILDLINK3=	YES
USE_X11=	YES

LDFLAGS+=	-lm

.include "../../graphics/Mesa/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
