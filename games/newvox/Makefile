# $NetBSD: Makefile,v 1.14 2004/06/15 13:11:03 grant Exp $
#

DISTNAME=	newvox-1.0
PKGREVISION=	2
CATEGORIES=	games
MASTER_SITES=	http://www.libsdl.org/projects/newvox/src/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.libsdl.org/projects/newvox/index.html
COMMENT=	Voxel-style landscape rendering fly-by

USE_BUILDLINK3=	YES
USE_X11=	YES
GNU_CONFIGURE=	YES

LIBS.SunOS+=	-lm

.include "../../devel/SDL/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
