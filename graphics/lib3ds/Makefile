# $NetBSD: Makefile,v 1.6 2003/07/17 21:41:26 grant Exp $
#

DISTNAME=	lib3ds-1.2.0
PKGREVISION=	2
CATEGORIES=	graphics devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=lib3ds/}

MAINTAINER=	rh@NetBSD.org
HOMEPAGE=	http://lib3ds.sourceforge.net/
COMMENT=	3D Studio File Format Library

USE_BUILDLINK2=	YES
GNU_CONFIGURE=	YES

LDFLAGS+=	-lm

.include "../../graphics/Mesa/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
