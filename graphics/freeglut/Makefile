# $NetBSD: Makefile,v 1.3 2004/05/07 01:14:48 xtraeme Exp $
#

DISTNAME=	freeglut-2.2.0
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=freeglut/}

MAINTAINER=	tech-pkg@NetBSD.org
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
