# $NetBSD: Makefile,v 1.9 2019/02/18 01:34:12 kamil Exp $

GITHUB_PROJECT=	haxm
GITHUB_TAG=	3bdfd1a39021df9b4dfe69e05a277e4e6456494a
DISTNAME=	haxm-1.20190214.${GITHUB_TAG}
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GITHUB:=intel/}

PKGREVISION=	1

MAINTAINER=	kamil@NetBSD.org
HOMEPAGE=	https://github.com/intel/haxm/
COMMENT=	Intel Hardware Accelerated Execution Manager
LICENSE=	modified-bsd

WRKSRC=		${WRKDIR}/haxm-${GITHUB_TAG}

ONLY_FOR_PLATFORM=	NetBSD-*-x86_64
OSVERSION_SPECIFIC=	YES

BUILD_DEPENDS+=	nasm-[0-9]*:../../devel/nasm

BUILD_DIRS=	platforms/netbsd

.include "../../mk/bsd.prefs.mk"

BUILDLINK_PASSTHRU_DIRS+=	${BSDSRCDIR}/sys

MAKE_FLAGS+=	S=${BSDSRCDIR}/sys

BUILD_DEFS+=	BSDSRCDIR

.if !exists(${BSDSRCDIR}/sys)
PKG_FAIL_REASON+=	"BSDSRCDIR/sys specifies non-existing directory ${BSDSRCDIR}/sys"
.endif

.include "../../mk/compiler.mk"

.if !empty(PKGSRC_COMPILER:Mclang)
CFLAGS+=	-Wno-error=address-of-packed-member
.endif

KMOD=		haxm.kmod
KMODULEDIR=	stand/${MACHINE}/${OS_VERSION}/modules/haxm

INSTALLATION_DIRS+=	sbin		# auxiliary scripts
INSTALLATION_DIRS+=	${KMODULEDIR}

INSTALL_UNSTRIPPED=	yes # Kernel linker needs unstripped module

PLIST_SUBST+=	MACHINE=${MACHINE}

pre-configure:
.for file in haxm-mknod haxm-modunload
	${CP} ${FILESDIR}/${file} ${WRKSRC}
.endfor
	${SED} \
		-e 's|@PREFIX@|${PREFIX}|g' \
		-e 's|@MACHINE@|${MACHINE}|g' \
		-e 's|@OS_VERSION@|${OS_VERSION}|g' \
		${FILESDIR}/haxm-modload.in > ${WRKSRC}/haxm-modload

do-install:
	${RUN} cd ${WRKSRC}/platforms/netbsd && \
		${INSTALL_PROGRAM} ${KMOD} ${DESTDIR}${PREFIX}/${KMODULEDIR}
.for file in haxm-modload haxm-modunload haxm-mknod
	${RUN} cd ${WRKSRC} && \
		${INSTALL_SCRIPT} ${file} ${DESTDIR}${PREFIX}/sbin
.endfor


.include "../../mk/bsd.pkg.mk"
