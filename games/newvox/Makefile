# $NetBSD: Makefile,v 1.29 2025/01/06 21:49:15 ktnb Exp $
#

DISTNAME=	newvox-1.0
PKGREVISION=	9
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
