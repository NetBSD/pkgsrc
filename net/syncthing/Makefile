# $NetBSD: Makefile,v 1.51 2017/05/17 17:01:24 wiz Exp $

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
DISTNAME=	syncthing-0.14.28
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=syncthing/}

# Minor version updates may be committed without asking.  Major
# updates not following the above policy will be reverted.
COMMENT=	Keeps directories in sync across hosts
HOMEPAGE=	http://syncthing.net/
MAINTAINER=	gdt@NetBSD.org
LICENSE=	mpl-2.0

# System pax fails on NetBSD 6.  Just use gtar until this is understood.
EXTRACT_USING=		gtar

GITHUB_TAG=	v${PKGVERSION_NOREV}

BUILD_DEPENDS+=		go-[0-9]*:../../lang/go

USE_LANGUAGES=		# go
NO_CONFIGURE=		yes

INSTALLATION_DIRS=	bin

# Go has very strong notions of how building is supposed to work, and
# paths.  Until 0.14, syncthing had symlink workarounds to have
# sources be found via a gopath directory.  Then, building failed
# because the sources are not a subdirectory of a component of GOPATH..
# See the following discussion for some hints.
# http://stackoverflow.com/questions/18149601/go-install-always-fails-no-install-directory-outside-gopath#18164310

# Upstream's build instructions say to place tarball contents under a
# particular named subdirectory of gopath:
# https://docs.syncthing.net/dev/building.html
# We attempt to follow their instructions as closely as possible.

# We set up a gopath directory, and a directory where we will place
# the tarball contents.  We use the non-standard variable name
# WRKPLACE so that we can let WRKSRC refer to where pkgsrc naturally
# unpacked the tarball.
GOPATH=			${WRKDIR}/gopath
WRKPLACEP=		${GOPATH}/src/github.com/syncthing
WRKPLACE=		${WRKPLACEP}/syncthing

MAKE_ENV+=		GOPATH=${GOPATH}

# This used to be set; there seems to be no reason any longer.  To be
# pruned on 2016-11-04.
# INSTALL_UNSTRIPPED= yes

SUBST_CLASSES+=		version
SUBST_STAGE.version=	pre-build
SUBST_MESSAGE.version=	Fixing version string
SUBST_FILES.version=	build.go
SUBST_SED.version=	-e 's|runError("git", "describe", "--always", "--dirty")|runError("echo","v${PKGVERSION_NOREV}")|'
SUBST_SED.version+=	-e 's|runError("git", "show", "-s", "--format=%ct")|runError("false")|'

# Create WRKPLACE's parent, but not WRKPLACE.  Move the contents of
# the distribution tarball to the directory name desired by upstream's
# build instructions.  Make a symlink so that the rest of the pkgsrc
# machinery that expects ${WRKSRC} to contain the tarball contents
# works.
post-extract:
	${MKDIR} ${GOPATH}/src/github.com/syncthing/
	${MV} ${WRKSRC} ${WRKPLACE}
	${LN} -s ${WRKPLACE} ${WRKSRC}

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${PREFIX}/bin/go run build.go

# Binaries other than syncthing proper should perhaps be installed.
do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/syncthing ${DESTDIR}/${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
