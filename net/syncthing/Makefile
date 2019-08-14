# $NetBSD: Makefile,v 1.95 2019/08/14 15:45:44 bsiegert Exp $

# Upstream used to frequently break protocol compatibility, but since
# 2018 or so this has been much better.  While users of pkgsrc
# syncthing on multiple systems can update synchronously, an important
# use case is interoperating with syncthing-android.
#
# Therefore, pkgsrc will update to a new syncthing version
# (e.g. 0.14.x vs 1.0.x) if either there is no protocol break, or when
# a corresponding syncthing-android version becomes available in the
# f-droid.org repository:
#   https://f-droid.org/repository/browse/?fdid=com.nutomic.syncthingandroid
# Updates that could possibly break protocol compatibility with the
# current syncthing-android in f-droid must be tested against the
# android version from f-droid prior to commiting.  (This is an
# attempt to avoid having to version syncthing in pkgsrc.)
# Note that the android versioning is disconnected from syncthing versioning;
# see https://github.com/syncthing/syncthing-android/issues/652 for
# a fuller explanation.
DISTNAME=	syncthing-source-v1.2.0
PKGNAME=	${DISTNAME:S,source-v,,}
PKGREVISION=	2
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=syncthing/}
GITHUB_RELEASE=	v${PKGVERSION_NOREV}

# Minor version updates may be committed without asking.  Major
# updates not following the above policy will be reverted.
COMMENT=	Keeps directories in sync across hosts
HOMEPAGE=	https://syncthing.net/
MAINTAINER=	gdt@NetBSD.org
LICENSE=	mpl-2.0

# The 'zillode' dependency calls the compiler on certain archs.
USE_LANGUAGES=		c
NO_CONFIGURE=		yes
GO_SRCPATH=		github.com/syncthing/syncthing
GO_DIST_BASE=		syncthing
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

.include "../../mk/bsd.prefs.mk"

PKG_SYSCONFSUBDIR=	syncthing

SYNCTHING_USER?=	syncthing
SYNCTHING_GROUP?=	syncthing

PKG_GROUPS_VARS+=	SYNCTHING_GROUP
PKG_USERS_VARS+=	SYNCTHING_USER

OWN_DIRS_PERMS+=	${PKG_SYSCONFDIR} ${SYNCTHING_USER} ${SYNCTHING_GROUP} 0755
OWN_DIRS_PERMS+=	${VARBASE}/db/syncthing ${SYNCTHING_USER} ${SYNCTHING_GROUP} 0755

PKG_GROUPS=			${SYNCTHING_GROUP}
PKG_USERS=			${SYNCTHING_USER}:${SYNCTHING_GROUP}
PKG_HOME.${SYNCTHING_USER}=	${VARBASE}/db/syncthing

FILES_SUBST+=		SYNCTHING_USER=${SYNCTHING_USER}
FILES_SUBST+=		SYNCTHING_GROUP=${SYNCTHING_GROUP}

RCD_SCRIPTS+=		syncthing

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${GO} run build.go -no-upgrade build syncthing

# Binaries other than syncthing proper should perhaps be installed.
do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/syncthing ${DESTDIR}/${PREFIX}/bin

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
