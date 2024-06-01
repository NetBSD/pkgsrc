# $NetBSD: Makefile,v 1.19 2024/06/01 14:03:03 bsiegert Exp $

DISTNAME=	podman-4.4.1
GITHUB_TAG=	v${PKGVERSION_NOREV}
PKGREVISION=	11
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=containers/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/containers/podman/
COMMENT=	Tool for managing OCI containers and pods
LICENSE=	apache-2.0

USE_TOOLS+=	gmake gsed

.include "../../mk/bsd.prefs.mk"
.include "../../lang/go/version.mk"

TOOL_DEPENDS+=	${GO_PACKAGE_DEP}
DEPENDS+=	qemu-[0-9]*:../../emulators/qemu
DEPENDS+=	gvproxy-[0-9]*:../../net/gvproxy

SUBST_CLASSES+=		prefix
SUBST_FILES.prefix+=	pkg/machine/qemu/options_netbsd_arm64.go
SUBST_FILES.prefix+=	vendor/github.com/containers/common/pkg/config/config_darwin.go
SUBST_FILES.prefix+=	vendor/github.com/containers/common/pkg/config/config_netbsd.go
SUBST_FILES.prefix+=	vendor/github.com/containers/storage/types/options_netbsd.go
SUBST_STAGE.prefix=	pre-configure
SUBST_MESSAGE.prefix=	fix PREFIX inside patch
SUBST_VARS.prefix=	PREFIX VARBASE

CHECK_PORTABILITY_SKIP+=	vendor/github.com/containers/buildah/release.sh

.if ${OPSYS} != "Linux"
BUILD_TARGET=	podman-remote

INSTALLATION_DIRS+=	bin
do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/${OPSYS:tl}/podman ${DESTDIR}${PREFIX}/bin/podman
.endif

.include "../../mk/bsd.pkg.mk"
