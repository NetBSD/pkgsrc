# $NetBSD: Makefile,v 1.4 2001/08/29 22:41:13 jlam Exp $
#

DISTNAME=	newvox-1.0
CATEGORIES=	games
MASTER_SITES=	http://www.libsdl.org/projects/newvox/src/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.libsdl.org/projects/newvox/index.html
COMMENT=	voxel-style landscape rendering fly-by

USE_BUILDLINK_ONLY=	YES
GNU_CONFIGURE=		YES

.include "../../devel/SDL/buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
