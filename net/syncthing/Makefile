# $NetBSD: Makefile,v 1.12 2016/02/16 23:07:12 gdt Exp $

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
DISTNAME=	syncthing-0.12.19
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=syncthing/}

# Minor version updates may be committed without asking.  Major
# updates not following the above policy will be reverted.
COMMENT=	Keeps directories in sync across hosts
HOMEPAGE=	http://syncthing.net/
MAINTAINER=	gdt@NetBSD.org
LICENSE=	mpl-2.0

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

post-extract:
	${MKDIR} ${WRKDIR}/gopath/src/github.com/syncthing
	${LN} -s ${WRKSRC} ${WRKDIR}/gopath/src/github.com/syncthing/syncthing

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${PREFIX}/bin/go run build.go

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/syncthing ${DESTDIR}/${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
