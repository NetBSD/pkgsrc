# $NetBSD: Makefile,v 1.1.1.1 2002/09/06 00:52:28 rh Exp $
#

DISTNAME=		lib3ds-1.2.0
CATEGORIES=		graphics devel
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=lib3ds/}

MAINTAINER=		rh@netbsd.org
HOMEPAGE=		http://lib3ds.sourceforge.net/
COMMENT=		3D Studio File Format Library

USE_MESA=		YES
USE_BUILDLINK2=         YES
GNU_CONFIGURE=		YES
LDFLAGS+=		-lm

.include "../../graphics/Mesa/buildlink2.mk"
.include "../../graphics/glut/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
