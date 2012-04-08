# $NetBSD: Makefile,v 1.32.2.1 2012/04/08 09:18:54 sbd Exp $
#

DISTNAME=	ArX-2.2.4
PKGREVISION=	19
CATEGORIES=	devel scm
MASTER_SITES=	http://savannah.nongnu.org/download/arx/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.nongnu.org/arx/
COMMENT=	Distributed revision control system

BROKEN=		Has not been buildable for several years, and dead upstream.

BUILD_DEPENDS+=	scons-[0-9]*:../../devel/scons
DEPENDS+=	patch-[0-9]*:../../devel/patch
DEPENDS+=	diffutils-[0-9]*:../../devel/diffutils
DEPENDS+=	gtar-base-[0-9]*:../../archivers/gtar-base

BUILD_DEFS+=	GNU_PROGRAM_PREFIX
EVAL_PREFIX+=	PREFIX.diffutils=diffutils
EVAL_PREFIX+=	PREFIX.gtar-base=gtar-base

USE_TOOLS+=		pkg-config
USE_LANGUAGES=		c c++
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	ARXDIFF=${PREFIX.diffutils}/bin/${GNU_PROGRAM_PREFIX}diff
CONFIGURE_ARGS+=	ARXPATCH=${PREFIX.diffutils}/bin/${GNU_PROGRAM_PREFIX}patch
CONFIGURE_ARGS+=	ARXTAR=${PREFIX.gtar-base}/bin/${GNU_PROGRAM_PREFIX}tar
CONFIGURE_ARGS+=	ARXPKGCONFIG=${PKG_CONFIG:Q}
# XXX Python is needed for build only; this is handled by devel/scons
CONFIGURE_ARGS+=	ARXPYTHON=${TRUE:Q}

INSTALLATION_DIRS=	bin

INSTALL_ENV+=		prefix=${DESTDIR}${PREFIX}
INSTALL_ENV+=		mandir=${DESTDIR}${PREFIX}/${PKGMANDIR}

do-build:
	${RUN}${_ULIMIT_CMD}						\
	cd ${WRKSRC}							\
	&& ${SETENV} ${MAKE_ENV} ${PREFIX}/bin/scons

do-install:
	${RUN}${_ULIMIT_CMD}						\
	cd ${WRKSRC}							\
	&& ${SETENV} ${MAKE_ENV} ${PREFIX}/bin/scons install

.include "../../sysutils/gnome-vfs/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
