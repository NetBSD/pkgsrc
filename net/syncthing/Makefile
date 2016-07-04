# $NetBSD: Makefile,v 1.23 2016/07/04 13:43:22 abs Exp $

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
DISTNAME=	syncthing-0.13.10
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

MAKE_ENV+=		GOPATH=${WRKDIR}/gopath
INSTALL_UNSTRIPPED=	yes	# XXX for Mac OS?

SUBST_CLASSES+=		version
SUBST_STAGE.version=	pre-build
SUBST_MESSAGE.version=	Fixing version string
SUBST_FILES.version=	build.go
SUBST_SED.version=	-e 's|runError("git", "describe", "--always", "--dirty")|runError("echo","v${PKGVERSION_NOREV}")|'
SUBST_SED.version+=	-e 's|runError("git", "show", "-s", "--format=%ct")|runError("false")|'

# The following is more complicated than the build documenation says,
# but appears necessary to link in both syncthing sources and the
# included sources.
post-extract:
	${MKDIR} ${WRKDIR}/gopath/src/github.com/syncthing
	${MKDIR} ${WRKDIR}/gopath/src/golang.org
	${LN} -s ${WRKSRC} ${WRKDIR}/gopath/src/github.com/syncthing/syncthing
	${LN} -s ${WRKSRC}/vendor/github.com/* ${WRKDIR}/gopath/src/github.com
	${LN} -s ${WRKSRC}/vendor/golang.org/* ${WRKDIR}/gopath/src/golang.org

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${PREFIX}/bin/go run build.go

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/syncthing ${DESTDIR}/${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
