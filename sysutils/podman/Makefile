# $NetBSD: Makefile,v 1.20 2024/06/03 02:07:44 maya Exp $

DISTNAME=	podman-5.0.3
GITHUB_TAG=	v${PKGVERSION_NOREV}
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

post-extract:
	${CP}	${FILESDIR}/options_netbsd.go	${WRKSRC}/vendor/github.com/containers/storage/types/
	${CP}	${FILESDIR}/config_netbsd.go	${WRKSRC}/vendor/github.com/containers/common/pkg/config/
	${CP}	${FILESDIR}/default_netbsd.go	${WRKSRC}/vendor/github.com/containers/common/pkg/config/
	${CP}	${FILESDIR}/ignition_netbsd.go	${WRKSRC}/pkg/machine/ignition/
	${MV}	${WRKSRC}/pkg/machine/env/dir_freebsd.go	${WRKSRC}/pkg/machine/env/dir_bsd.go

SUBST_CLASSES+=		prefix
SUBST_FILES.prefix+=	vendor/github.com/containers/common/pkg/config/default_netbsd.go
SUBST_FILES.prefix+=	vendor/github.com/containers/common/pkg/config/config_netbsd.go
SUBST_FILES.prefix+=	vendor/github.com/containers/storage/types/options_netbsd.go
SUBST_STAGE.prefix=	pre-configure
SUBST_MESSAGE.prefix=	fix PREFIX inside patch
SUBST_VARS.prefix=	PREFIX VARBASE PKG_SYSCONFDIR

CHECK_PORTABILITY_SKIP+=	vendor/github.com/containers/buildah/release.sh

.if ${OPSYS} != "Linux"
BUILD_TARGET=	podman-remote

INSTALLATION_DIRS+=	bin
do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/podman-remote ${DESTDIR}${PREFIX}/bin/podman
.endif

.include "../../mk/bsd.pkg.mk"
