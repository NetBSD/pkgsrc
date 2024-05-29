# $NetBSD: Makefile,v 1.24 2024/05/29 16:32:30 adam Exp $

DISTNAME=	ori-0.8.2
PKGREVISION=	10
CATEGORIES=	filesystems
MASTER_SITES=	https://bitbucket.org/orifs/ori/downloads/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ori.scs.stanford.edu/
COMMENT=	Secure distributed file system
LICENSE=	isc

USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config

# (insert swearing)
CWRAPPERS_APPEND.cxx+=	-Wno-narrowing

SCONS_INSTALL_ARGS+=	DESTDIR=${DESTDIR}

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

.include "../../archivers/xz/buildlink3.mk"
BUILDLINK_API_DEPENDS.libevent+=	libevent>=2.0
.include "../../devel/libevent/buildlink3.mk"
PYTHON_FOR_BUILD_ONLY=	yes
.include "../../devel/scons4/build.mk"
.include "../../mk/fuse.buildlink3.mk"
.include "../../net/mDNSResponder/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
