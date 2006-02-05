# $NetBSD: Makefile,v 1.11 2006/02/05 23:09:34 joerg Exp $
#

DISTNAME=	lib3ds-1.2.0
PKGREVISION=	4
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
