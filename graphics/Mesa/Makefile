# $NetBSD: Makefile,v 1.71 2015/04/03 02:29:40 tnn Exp $

PKGNAME=	Mesa-7.11.2
MASTER_SITES=	# empty
DISTFILES=	# empty
CATEGORIES=	graphics

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Graphics library meta package, similar to SGI's OpenGL

META_PACKAGE=	# empty

CONFLICTS=	Mesa-glx-[0-9]*

# The ordering is important here as glut/buildlink3.mk sets the version
# of Mesa required.
.include "../../graphics/glut/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
