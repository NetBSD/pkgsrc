# $NetBSD: Makefile,v 1.3 2001/06/29 04:54:53 jlam Exp $
#

DISTNAME=	newvox-1.0
CATEGORIES=	games
MASTER_SITES=	http://www.libsdl.org/projects/newvox/src/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.libsdl.org/projects/newvox/index.html
COMMENT=	voxel-style landscape rendering fly-by

USE_BUILDLINK_ONLY=	YES
GNU_CONFIGURE=		YES
USE_X11=		YES

.include "../../devel/SDL/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
