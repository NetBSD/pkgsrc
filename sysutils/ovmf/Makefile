# $NetBSD: Makefile,v 1.1 2017/10/23 14:21:57 maya Exp $

GITHUB_PROJECT=	edk2
PKGNAME=	OVMF-0.0.2017624
DISTNAME=	vUDK2017
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=tianocore/}
DIST_SUBDIR=	${GITHUB_PROJECT}
GITHUB_TAG=	${DISTNAME}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/tianocore/edk2/
COMMENT=	Sample UEFI firmware for virtual machines
LICENSE=	modified-bsd

WRKSRC=		${WRKDIR}/${GITHUB_PROJECT}-${GITHUB_TAG}

USETOOLS+=	gmake bash
USE_LANGUAGES=	c c++

PYTHON_VERSIONS_ACCEPTED=	27
SUBST_CLASSES+=		python
SUBST_STAGE.python=	pre-configure
SUBST_MESSAGE.python=	Fix python binary
SUBST_FILES.python=	BaseTools/Tests/GNUmakefile
SUBST_FILES.python+=	BaseTools/BinWrappers/PosixLike/*
SUBST_SED.python=	-e 's,python2,${PYTHONBIN},g'

PKGSRC_USE_SSP=		no

do-build:
	cd ${WRKSRC}/OvmfPkg && \
	export MAKE=gmake && \
	${MAKE_BUILD_ENV} ./build.sh

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/Build/Ovmf*/*/FV/OVMF.fd ${DESTDIR}${PREFIX}/share

BUILD_DEPENDS+=	nasm-[0-9]*:../../devel/nasm

.include "../../lang/python/application.mk"
.include "../../devel/libuuid/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
