# $NetBSD: opensbi.mk,v 1.2 2024/06/17 21:53:57 gutteridge Exp $

.include "../../sysutils/opensbi/opensbi-version.mk"

PKGNAME?=		opensbi-${OPENSBI_BOARD}-${OPENSBI_VERSION:S/-/./}
DISTNAME?=		opensbi-${OPENSBI_VERSION}
DISTINFO_FILE?=		${.CURDIR}/../../sysutils/opensbi/distinfo
CATEGORIES=		sysutils
EXTRACT_SUFX=		.tar.gz

GITHUB_PROJECT?=	opensbi
GITHUB_TAG?=		v1.4
MASTER_SITES?=		${MASTER_SITE_GITHUB:=riscv-software-src/}
DIST_SUBDIR?=		${GITHUB_PROJECT}

COMMENT=		RISC-V Open Source Supervisor Binary Interface (OpenSBI)
LICENSE=		2-clause-bsd

USE_TOOLS+=		gmake
TOOL_DEPENDS+=		dtc>=1.4.2:../../sysutils/dtc
BUILD_DEPENDS+=		cross-riscv64-none-elf-gcc-[0-9]*:../../cross/riscv64-none-elf-gcc

OPENSBI_ENV+=		CROSS_COMPILE=${PREFIX}/cross-riscv64-none-elf/bin/riscv64-none-elf-
OPENSBI_ENV+=		PLATFORM=${OPENSBI_PLATFORM}

PYTHON_VERSIONS_INCOMPATIBLE=	27
PYTHON_FOR_BUILD_ONLY=		yes
.include "../../lang/python/tool.mk"

MAKE_ENV+=		${OPENSBI_ENV}

INSTALLATION_DIRS+=	share/opensbi/${OPENSBI_BOARD}

do-install:
.for bin in ${OPENSBI_BIN}
	${INSTALL_DATA} ${WRKSRC}/build/platform/${OPENSBI_PLATFORM}/firmware/${bin} \
	    ${DESTDIR}${PREFIX}/share/opensbi/${OPENSBI_BOARD}
.endfor
