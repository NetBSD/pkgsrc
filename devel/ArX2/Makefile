# $NetBSD: Makefile,v 1.9 2005/12/05 20:50:01 rillig Exp $
#

DISTNAME=	ArX-2.2.3
CATEGORIES=	devel
MASTER_SITES=	http://savannah.nongnu.org/download/arx/

MAINTAINER=	recht@NetBSD.org
HOMEPAGE=	http://www.nongnu.org/arx/
COMMENT=	Distributed revision control system

DEPENDS+=	patch-[0-9]*:../../devel/patch
DEPENDS+=	diffutils-[0-9]*:../../devel/diffutils
DEPENDS+=	gtar-base-[0-9]*:../../archivers/gtar-base
BUILD_DEPENDS+=	scons-[0-9]*:../../devel/scons

USE_TOOLS+=		pkg-config
USE_LANGUAGES=		c c++
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	ARXDIFF=${LOCALBASE}/bin/${GNU_PROGRAM_PREFIX}diff
CONFIGURE_ARGS+=	ARXPATCH=${LOCALBASE}/bin/${GNU_PROGRAM_PREFIX}patch
CONFIGURE_ARGS+=	ARXTAR=${LOCALBASE}/bin/${GNU_PROGRAM_PREFIX}tar
CONFIGURE_ARGS+=	ARXPKGCONFIG=${PKG_CONFIG:Q}
# XXX Python is needed for build only; this is handled by devel/scons
CONFIGURE_ARGS+=	ARXPYTHON=${TRUE:Q}

IMG_FILES=	ArX001.png ArX002.png ArX003.png ArX004.png
DOC_FILES=	ArX.html ArX.pdf ${IMG_FILES}
DOCDIR=		${PREFIX}/share/doc/ArX

INSTALLATION_DIRS=	bin

do-build:
	${_PKG_SILENT}${_PKG_DEBUG}${_ULIMIT_CMD}cd ${WRKSRC} &&	\
		${SETENV} ${MAKE_ENV} ${PREFIX}/bin/scons

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/build/arx/arx ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${DOCDIR}
.for f in ${DOC_FILES}
	${INSTALL_DATA} ${WRKSRC}/docs/${f} ${DOCDIR}
.endfor

.include "../../sysutils/gnome-vfs2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
