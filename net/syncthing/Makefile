# $NetBSD: Makefile,v 1.186 2024/06/01 14:02:57 bsiegert Exp $

# Protocol breaks require tech-pkg@ discussion and MAINTAINER approval.
DISTNAME=	syncthing-source-v1.26.1
PKGNAME=	${DISTNAME:S,source-v,,}
PKGREVISION=	4
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=syncthing/}
GITHUB_RELEASE=	v${PKGVERSION_NOREV}

COMMENT=	Keeps directories in sync across hosts
HOMEPAGE=	https://syncthing.net/
MAINTAINER=	gdt@NetBSD.org
LICENSE=	mpl-2.0

# The 'zillode' dependency calls the compiler on certain archs.
USE_LANGUAGES=		c
WRKSRC=			${WRKDIR}/syncthing
NO_CONFIGURE=		yes
INSTALLATION_DIRS=	bin share/applications

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
SUBST_FILES.go=		lib/api/auto/doc.go cmd/strelaypoolsrv/auto/doc.go
SUBST_SED.go+=		-e 's|go run|"${GO}" run|'

SUBST_CLASSES+=		bin
SUBST_STAGE.bin=	pre-install
SUBST_MESSAGE.bin=	Fixing location of installed binaries
SUBST_FILES.bin=	etc/linux-desktop/*.desktop
SUBST_SED.bin+=		-e 's,/usr/bin/syncthing,${PREFIX}/bin/syncthing,'

.include "../../mk/bsd.prefs.mk"

PKG_SYSCONFSUBDIR=	syncthing

SYNCTHING_USER?=	syncthing
SYNCTHING_GROUP?=	syncthing

PKG_GROUPS_VARS+=	SYNCTHING_GROUP
PKG_USERS_VARS+=	SYNCTHING_USER

BUILD_DEFS+=		VARBASE

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
	${INSTALL_PROGRAM} ${WRKSRC}/syncthing ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/etc/linux-desktop/*.desktop ${DESTDIR}${PREFIX}/share/applications
.for s in 512 256 128 64 32
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/icons/hicolor/${s}x${s}/apps
	${INSTALL_DATA} ${WRKSRC}/assets/logo-${s}.png  \
		${DESTDIR}${PREFIX}/share/icons/hicolor/${s}x${s}/apps/syncthing.png
.endfor

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
