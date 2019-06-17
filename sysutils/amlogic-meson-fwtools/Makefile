# $NetBSD: Makefile,v 1.3 2019/06/17 17:08:26 gdt Exp $

# Version isn't super-meaningful; we're grabbing a collection of non-changing
# tools from a variety of locations.
VERSION=	0.0

PKGNAME=	amlogic-meson-fwtools-${VERSION}
PKGREVISION=	1		# bump this when a tool is added/removed
CATEGORIES=	sysutils

MAINTAINER=	port-arm@NetBSD.org
COMMENT=	Trusted Firmware packaging tools for the Amlogic Meson family of SoCs

LICENSE=	amlogic-meson-fwtools-license

RESTRICTED=	Redistribution not permitted - see licenses/amlogic-meson-fwtools
NO_SRC_ON_FTP=		${RESTRICTED}
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}

#
# These tools are distributed only as Linux x86_64 binaries.
#

EMUL_PLATFORMS=		linux-x86_64
EMUL_MODULES.linux=	base

NO_CONFIGURE=	yes
NO_BUILD=	yes

#
# Hardkernel-supplied firmware tools
#
ODROID=                 odroidc2-v2015.01

xFIPCREATE=		fip_create
FIPCREATE=		${ODROID}-${xFIPCREATE}
DISTFILES+=		${FIPCREATE}
SITES.${FIPCREATE}=	${MASTER_SITE_GITHUB:@url@ \
	-${url}hardkernel/u-boot/raw/${ODROID}/fip/${xFIPCREATE} @}

xAML_ENCRYPT_GXB=	aml_encrypt_gxb
AML_ENCRYPT_GXB=	${ODROID}-${xAML_ENCRYPT_GXB}
DISTFILES+=		${AML_ENCRYPT_GXB}
SITES.${AML_ENCRYPT_GXB}=${MASTER_SITE_GITHUB:@url@ \
	-${url}hardkernel/u-boot/raw/${ODROID}/fip/gxb/${xAML_ENCRYPT_GXB} @}

#
# BayLibre-supplied firmware tools
#
LIBRETECH=		libretech-cc

xAML_ENCRYPT_GXL=	aml_encrypt_gxl
AML_ENCRYPT_GXL=	${LIBRETECH}-${xAML_ENCRYPT_GXL}
DISTFILES+=		${AML_ENCRYPT_GXL}
SITES.${AML_ENCRYPT_GXL}=${MASTER_SITE_GITHUB:@url@ \
	-${url}BayLibre/u-boot/raw/${LIBRETECH}/fip/gxl/${xAML_ENCRYPT_GXL} @}

INSTALLATION_DIRS+=	bin

do-extract:
	# Nothing to do.
	${TRUE}

do-install:
	${INSTALL_PROGRAM} ${DISTDIR}/${FIPCREATE} \
		${DESTDIR}${PREFIX}/bin/aml_fip_create
	${INSTALL_PROGRAM} ${DISTDIR}/${AML_ENCRYPT_GXB} \
		${DESTDIR}${PREFIX}/bin/aml_encrypt_gxb
	${INSTALL_PROGRAM} ${DISTDIR}/${AML_ENCRYPT_GXL} \
		${DESTDIR}${PREFIX}/bin/aml_encrypt_gxl

.include "../../mk/bsd.pkg.mk"
