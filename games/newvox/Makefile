# $NetBSD: Makefile,v 1.15 2004/10/03 00:14:46 tv Exp $
#

DISTNAME=	newvox-1.0
PKGREVISION=	3
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
