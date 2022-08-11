# $NetBSD: Makefile,v 1.16 2022/08/11 05:08:46 gutteridge Exp $

DISTNAME=	qore-glut-module-0.0.3
PKGREVISION=	14
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

BROKEN=		"This package has not been updated to use the new Qore apis and breaks because of that."

.include "options.mk"

.include "../../graphics/freeglut/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../lang/qore/module.mk"
.include "../../graphics/qore-opengl-module/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
