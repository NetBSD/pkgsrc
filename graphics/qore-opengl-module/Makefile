# $NetBSD: Makefile,v 1.3 2016/03/05 11:27:50 jperkin Exp $

DISTNAME=	qore-opengl-module-0.0.3
PKGREVISION=	6
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=qore/}

MAINTAINER=	nros@users.sourceforge.net
HOMEPAGE=	http://www.qore.org/
COMMENT=	OpenGL Qore bindings
LICENSE=	gnu-lgpl-v2.1

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	autoconf automake gmake
PTHREAD_OPTS+=	native

pre-configure:
	set -e; cd ${WRKSRC}; \
	aclocal; autoheader; automake -a --foreign -i; autoconf

CONFIGURE_ARGS+=--with-opengl=${BUILDLINK_PREFIX.MesaLib}

INSTALLATION_DIRS+=     share/doc/${PKGBASE}
post-install:
	${INSTALL_DATA} ${WRKSRC}/docs/opengl-module-doc.html \
		${DESTDIR}${PREFIX}/share/doc/${PKGBASE}

.include "options.mk"

.include "../../graphics/glu/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../lang/qore/buildlink3.mk"
.include "../../lang/qore/module.mk"
.include "../../mk/bsd.pkg.mk"
