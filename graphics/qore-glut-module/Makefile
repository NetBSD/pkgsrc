# $NetBSD: Makefile,v 1.14 2021/12/08 16:05:04 adam Exp $

DISTNAME=	qore-glut-module-0.0.3
PKGREVISION=	13
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=qore/}

MAINTAINER=	nros@NetBSD.org
HOMEPAGE=	http://www.qore.org/
COMMENT=	GLUT Qore bindings
LICENSE=	gnu-lgpl-v2.1

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++11
PTHREAD_OPTS+=	native

CONFIGURE_ARGS+=	--with-glut=${BUILDLINK_PREFIX.freeglut}

.include "options.mk"

.include "../../graphics/freeglut/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../lang/qore/module.mk"
.include "../../graphics/qore-opengl-module/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
