# $NetBSD: Makefile,v 1.2 2002/10/20 13:24:27 wiz Exp $
#

DISTNAME=		lib3ds-1.2.0
CATEGORIES=		graphics devel
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=lib3ds/}

MAINTAINER=		rh@netbsd.org
HOMEPAGE=		http://lib3ds.sourceforge.net/
COMMENT=		3D Studio File Format Library

USE_BUILDLINK2=         YES
GNU_CONFIGURE=		YES
LDFLAGS+=		-lm

.include "../../graphics/Mesa/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
