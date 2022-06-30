# $NetBSD: Makefile,v 1.9 2022/06/30 11:18:51 nia Exp $

PKGNAME=		OVMF-0.0.20181116
PKGREVISION=		3
DISTNAME=		edk2-20181116
MASTER_SITES=		${MASTER_SITE_LOCAL}
CATEGORIES=		sysutils
# Require openssl submodule
#DISTNAME=		edk2-${GITHUB_TAG}
#MASTER_SITES=		${MASTER_SITE_GITHUB:=tianocore/}
#GITHUB_PROJECT=	edk2
#GITHUB_TAG=		edk2-stable201811
#MASTER_SITES=		${MASTER_SITE_GITHUB:=tianocore/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/tianocore/edk2/
COMMENT=	Sample UEFI firmware for virtual machines
LICENSE=	modified-bsd

SSP_SUPPORTED=		no

.include "../../mk/bsd.prefs.mk"
ONLY_FOR_PLATFORM=	*-*-i386 *-*-x86_64

PLIST_VARS+=	x32 x64

.if !empty(MACHINE_PLATFORM:M*-*-i386)
TARGET_ARCHS=	IA32
PLIST.x32=	yes
.elif !empty(MACHINE_PLATFORM:M*-*-x86_64)
TARGET_ARCHS=	X64
PLIST.x64=	yes
.endif

USE_TOOLS+=	gmake bash
USE_LANGUAGES=	c c++

PYTHON_VERSIONS_ACCEPTED=	27
SUBST_CLASSES+=			python
SUBST_STAGE.python=		pre-configure
SUBST_MESSAGE.python=		Fix python binary
SUBST_FILES.python=		BaseTools/Tests/GNUmakefile
SUBST_FILES.python+=		BaseTools/BinWrappers/PosixLike/*
SUBST_SED.python=		-e 's,python2,${PYTHONBIN},g'

do-build:
.for ARCH in ${TARGET_ARCHS}
	cd ${WRKSRC}/OvmfPkg && \
	${SETENV} ${MAKE_ENV} ./build.sh -a ${ARCH}
	${CP} ${WRKSRC}/Build/Ovmf${ARCH:S/IA/Ia/}/*/FV/OVMF.fd \
		${WRKSRC}/OVMF${ARCH}.fd
.endfor

INSTALLATION_DIRS+=	share/ovmf
do-install:
	${INSTALL_DATA} ${WRKSRC}/OVMF*.fd ${DESTDIR}${PREFIX}/share/ovmf/

BUILD_DEPENDS+=	acpica-utils-[0-9]*:../../sysutils/acpica-utils
BUILD_DEPENDS+=	nasm-[0-9]*:../../devel/nasm
BUILD_DEPENDS+=	${PYPKGPREFIX}-sqlite3-[0-9]*:../../databases/py-sqlite3

.include "../../lang/python/application.mk"
.include "../../devel/libuuid/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
