# $NetBSD: Makefile,v 1.2 2004/04/20 00:12:57 minskim Exp $
#

DISTNAME=	freeglut-2.2.0
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=freeglut/}

MAINTAINER=	xtraeme@NetBSD.org
HOMEPAGE=	http://freeglut.sourceforge.net/
COMMENT=	Alternative to the OpenGL Utility Toolkit (GLUT) library

CONFLICTS=	glut-[0-9]*:../../graphics/glut

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=	yes
USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes
USE_GNU_TOOLS+=	make
USE_X11=	yes

.include "../../mk/bsd.pkg.mk"
