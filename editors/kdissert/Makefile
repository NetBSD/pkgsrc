# $NetBSD: Makefile,v 1.53 2014/05/09 07:37:04 wiz Exp $

DISTNAME=	kdissert-1.0.7
PKGREVISION=	28
CATEGORIES=	editors
MASTER_SITES=	http://freehackers.org/~tnagy/kdissert/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://freehackers.org/~tnagy/kdissert/
COMMENT=	Mindmapping-like tool to generate text templates
LICENSE=	gnu-gpl-v2

USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_TOOLS+=		msgfmt
PYTHON_FOR_BUILD_ONLY=	yes
PYTHON_VERSIONS_INCOMPATIBLE=	33 34 # not yet ported as of 1.0.7

do-configure:
	${RUN} ${_ULIMIT_CMD} \
	cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} \
	${PYTHONBIN} waf configure --prefix=''

do-build:
	${RUN} ${_ULIMIT_CMD} \
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${PYTHONBIN} waf

do-install:
	${RUN} ${_ULIMIT_CMD} \
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} \
	${PYTHONBIN} waf install --destdir=${DESTDIR}

.include "../../lang/python/application.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../x11/qt3-tools/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
