# $NetBSD: Makefile,v 1.78 2018/11/04 18:38:04 bsiegert Exp $

# Upstream regularly breaks protocol compatibility.  While users of
# pkgsrc syncthing on multiple systems can update synchronously, an
# important use case is interoperating with syncthing-android.
# Therefore, pkgsrc will update to a new major version (e.g. 0.12.x vs
# 0.11.x) when a corresponding syncthing-android version becomes
# available in the f-droid.org repository:
# https://f-droid.org/repository/browse/?fdid=com.nutomic.syncthingandroid
# Updates to new major versions must be tested against the android
# version from f-droid prior to commiting.  (This is an attempt to
# avoid having to version syncthing in pkgsrc.)
# Note that the android versioning is disconnected from syncthing versioning;
# see https://github.com/syncthing/syncthing-android/issues/652 for
# a fuller explanation.
DISTNAME=	syncthing-0.14.51
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=syncthing/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

# Minor version updates may be committed without asking.  Major
# updates not following the above policy will be reverted.
COMMENT=	Keeps directories in sync across hosts
HOMEPAGE=	https://syncthing.net/
MAINTAINER=	gdt@NetBSD.org
LICENSE=	mpl-2.0

# System pax fails on NetBSD 6.  Just use bsdtar until this is understood.
EXTRACT_USING=		bsdtar

# The 'zillode' dependency calls the compiler on certain archs.
USE_LANGUAGES=		c
NO_CONFIGURE=		yes
GO_SRCPATH=		github.com/syncthing/syncthing
GO_DIST_BASE=		${PKGNAME_NOREV}
INSTALLATION_DIRS=	bin

CHECK_RELRO_SKIP+=	bin/syncthing

SUBST_CLASSES+=		version
SUBST_STAGE.version=	pre-build
SUBST_MESSAGE.version=	Fixing version string
SUBST_FILES.version=	build.go
SUBST_SED.version=	-e 's|runError("git", "describe", "--always", "--dirty")|runError("echo","v${PKGVERSION_NOREV}")|'
SUBST_SED.version+=	-e 's|runError("git", "show", "-s", "--format=%ct")|runError("false")|'
SUBST_SED.version+=	-e 's|"go"|"${GO}"|'

SUBST_CLASSES+=		go
SUBST_STAGE.go=		pre-build
SUBST_MESSAGE.go=	Fixing go executable reference
SUBST_FILES.go=		lib/auto/doc.go cmd/strelaypoolsrv/auto/doc.go
SUBST_SED.go+=		-e 's|go run|"${GO}" run|'

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${GO} run build.go build syncthing

# Binaries other than syncthing proper should perhaps be installed.
do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/syncthing ${DESTDIR}/${PREFIX}/bin

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
