# $NetBSD: Makefile,v 1.10 2005/06/01 18:02:56 jlam Exp $
#

DISTNAME=	lib3ds-1.2.0
PKGREVISION=	3
CATEGORIES=	graphics devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=lib3ds/}

MAINTAINER=	rh@NetBSD.org
HOMEPAGE=	http://lib3ds.sourceforge.net/
COMMENT=	3D Studio File Format Library

GNU_CONFIGURE=	YES

LDFLAGS+=	-lm

.include "../../graphics/Mesa/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
