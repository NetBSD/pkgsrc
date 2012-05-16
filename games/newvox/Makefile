# $NetBSD: Makefile,v 1.24 2012/05/16 15:11:15 marino Exp $
#

DISTNAME=	newvox-1.0
PKGREVISION=	7
CATEGORIES=	games
MASTER_SITES=	http://www.libsdl.org/projects/newvox/src/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.libsdl.org/projects/newvox/index.html
COMMENT=	Voxel-style landscape rendering fly-by

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	YES

LIBS.SunOS+=	-lm
LDFLAGS.DragonFly=	-lm

.include "../../devel/SDL/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
