# $NetBSD: Makefile,v 1.21 2010/02/03 21:55:04 joerg Exp $
#

DISTNAME=		kdissert-1.0.7
PKGREVISION=		3
CATEGORIES=		editors
MASTER_SITES=		http://freehackers.org/~tnagy/kdissert/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://freehackers.org/~tnagy/kdissert/
COMMENT=		Mindmapping-like tool to generate text templates

PKG_DESTDIR_SUPPORT=	user-destdir

USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c c++
USE_TOOLS+=		msgfmt
PYTHON_FOR_BUILD_ONLY=	yes

do-configure:
	${RUN} ${_ULIMIT_CMD} \
	cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} \
	${PYTHONBIN} waf configure --prefix=${PTEFIX}

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
.include "../../mk/bsd.pkg.mk"
