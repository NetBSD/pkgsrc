# $NetBSD: Makefile,v 1.21 2006/03/04 21:29:43 jlam Exp $
#

DISTNAME=	newvox-1.0
PKGREVISION=	6
CATEGORIES=	games
MASTER_SITES=	http://www.libsdl.org/projects/newvox/src/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.libsdl.org/projects/newvox/index.html
COMMENT=	Voxel-style landscape rendering fly-by

GNU_CONFIGURE=	YES

LIBS.SunOS+=	-lm

.include "../../devel/SDL/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
