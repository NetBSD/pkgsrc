# $NetBSD: Makefile,v 1.5 2016/03/25 21:13:51 joerg Exp $

DISTNAME=	ori-0.8.1
PKGREVISION=	2
CATEGORIES=	filesystems
MASTER_SITES=	https://bitbucket.org/orifs/ori/downloads/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ori.scs.stanford.edu/
COMMENT=	Secure distributed file system
LICENSE=	isc

BUILD_DEPENDS+=	scons>=2.0:../../devel/scons

USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config

SUBST_CLASSES+=		man
SUBST_SED.man+=		-e "s,share/man,${PKGMANDIR},"
SUBST_FILES.man+=	SConstruct
SUBST_STAGE.man=	pre-build
SUBST_MESSAGE.man=	Fixing man page installation path.

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
_WRAP_EXTRA_ARGS.CXX+=	-D_KERNTYPES
CWRAPPERS_APPEND.cxx+=	-D_KERNTYPES
.endif

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${PREFIX}/bin/scons

do-install:
	cd ${WRKSRC} && ${SETENV} ${INSTALL_ENV} ${PREFIX}/bin/scons install PREFIX=${DESTDIR}${PREFIX}

# configure script demands libevent 2.0 or greater
BUILDLINK_API_DEPENDS.libevent+=	libevent>=2.0

.include "../../archivers/xz/buildlink3.mk"
.include "../../devel/boost-headers/buildlink3.mk"
.include "../../devel/libevent/buildlink3.mk"
.include "../../mk/fuse.buildlink3.mk"
.include "../../net/mDNSResponder/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
