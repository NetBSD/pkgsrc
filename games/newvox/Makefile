# $NetBSD: Makefile,v 1.22 2006/06/12 16:28:10 wiz Exp $
#

DISTNAME=	newvox-1.0
PKGREVISION=	7
CATEGORIES=	games
MASTER_SITES=	http://www.libsdl.org/projects/newvox/src/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.libsdl.org/projects/newvox/index.html
COMMENT=	Voxel-style landscape rendering fly-by

GNU_CONFIGURE=	YES

LIBS.SunOS+=	-lm

.include "../../devel/SDL/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
