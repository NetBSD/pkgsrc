# $NetBSD: Makefile,v 1.27 2018/01/14 17:34:00 rillig Exp $
#

DISTNAME=	newvox-1.0
PKGREVISION=	8
CATEGORIES=	games
MASTER_SITES=	http://www.libsdl.org/projects/newvox/src/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.libsdl.org/projects/newvox/index.html
COMMENT=	Voxel-style landscape rendering fly-by

GNU_CONFIGURE=	YES

LIBS.SunOS+=		-lm
LDFLAGS.DragonFly=	-lm

.include "../../devel/SDL/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
