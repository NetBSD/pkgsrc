# $NetBSD: arm-trusted-firmware.mk,v 1.1 2020/06/30 14:33:14 thorpej Exp $

.include "../../sysutils/arm-trusted-firmware/arm-trusted-firmware-dist.mk"

PKGNAME?=	${GITHUB_PROJECT}-${PLATFORM}-${VERSION}

MAKE_FLAGS+=	CROSS_COMPILE=${PREFIX}/cross-aarch64-none-elf/bin/aarch64-none-elf-
.if !empty(ATF_CORTEX_M0:Myes)
MAKE_FLAGS+=	M0_CROSS_COMPILE=${PREFIX}/cross-arm-none-eabi/bin/arm-none-eabi-
.endif
MAKE_FLAGS+=	PLAT=${PLATFORM}
MAKE_FLAGS+=	CFLAGS='-gdwarf-2'
#MAKE_FLAGS+=	DEBUG=1
#MAKE_FLAGS+=	LOG_LEVEL=50
#MAKE_FLAGS+=	V=1
MAKE_FLAGS+=	BUILD_STRING=${GITHUB_TAG}
BUILD_TARGET=	bl31

BUILD_DEPENDS+=	cross-aarch64-none-elf-gcc-[0-9]*:../../cross/aarch64-none-elf-gcc
.if !empty(ATF_CORTEX_M0:Myes)
BUILD_DEPENDS+=	cross-arm-none-eabi-gcc-[0-9]*:../../cross/arm-none-eabi-gcc
.endif

.if empty(MAKE_FLAGS:MDEBUG=1)
BL31_DIR=release
.else
BL31_DIR=debug
.endif

BL31_SUFFIX?=	bin

.if !target(do-install)
do-install:
	${INSTALL_DATA_DIR} \
	     ${DESTDIR}${PREFIX}/share/arm-trusted-firmware/${PLATFORM}
.if ${BL31_SUFFIX} == "bin"
	${INSTALL_DATA} \
	    ${WRKSRC}/build/${PLATFORM}/${BL31_DIR}/bl31.${BL31_SUFFIX} \
	    ${DESTDIR}${PREFIX}/share/arm-trusted-firmware/${PLATFORM}/
.else
	${INSTALL_DATA} \
	    ${WRKSRC}/build/${PLATFORM}/${BL31_DIR}/bl31/bl31.${BL31_SUFFIX} \
	    ${DESTDIR}${PREFIX}/share/arm-trusted-firmware/${PLATFORM}/
.endif
.endif

# XXX kludge. pkgsrc passes down run path flags in LDFLAGS assuming
# gcc is used for linking, but here we call the linker directly.
COMPILER_RPATH_FLAG=	-R

.include "../../mk/bsd.pkg.mk"
