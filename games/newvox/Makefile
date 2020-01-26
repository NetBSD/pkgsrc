# $NetBSD: Makefile,v 1.28 2020/01/26 17:31:16 rillig Exp $
#

DISTNAME=	newvox-1.0
PKGREVISION=	8
CATEGORIES=	games
MASTER_SITES=	http://www.libsdl.org/projects/newvox/src/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.libsdl.org/projects/newvox/index.html
COMMENT=	Voxel-style landscape rendering fly-by

GNU_CONFIGURE=	YES

LIBS.SunOS+=		-lm
LDFLAGS.DragonFly=	-lm

.include "../../devel/SDL/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
