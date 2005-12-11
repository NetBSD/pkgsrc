# $NetBSD: Makefile,v 1.19 2005/12/11 09:40:42 wiz Exp $
#

DISTNAME=	newvox-1.0
PKGREVISION=	5
CATEGORIES=	games
MASTER_SITES=	http://www.libsdl.org/projects/newvox/src/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.libsdl.org/projects/newvox/index.html
COMMENT=	Voxel-style landscape rendering fly-by

GNU_CONFIGURE=	YES

LIBS.SunOS+=	-lm

.include "../../devel/SDL/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
