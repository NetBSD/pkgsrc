# $NetBSD: Makefile,v 1.23 2008/06/20 01:09:20 joerg Exp $
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

.include "../../devel/SDL/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
