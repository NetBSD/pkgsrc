# $NetBSD: Makefile,v 1.2 2021/09/04 21:14:15 leot Exp $

DISTNAME=	podman-3.3.1
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

BUILD_DEPENDS+=	${GO_PACKAGE_DEP}
DEPENDS+=	qemu-[0-9]*:../../emulators/qemu
DEPENDS+=	gvproxy-[0-9]*:../../net/gvproxy

SUBST_CLASSES+=		gvproxy
SUBST_FILES.gvproxy=	pkg/machine/qemu/machine.go
SUBST_STAGE.gvproxy=	pre-configure
SUBST_MESSAGE.gvproxy=	fix PREFIX inside patch
SUBST_VARS.gvproxy=	PREFIX

.if ${OPSYS} != "Linux"
BUILD_TARGET=	podman-remote-${OPSYS:tl}

INSTALLATION_DIRS+=	bin
do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/${OPSYS:tl}/podman ${DESTDIR}${PREFIX}/bin/podman
.endif

.include "../../mk/bsd.pkg.mk"
