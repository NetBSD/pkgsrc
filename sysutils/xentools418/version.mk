# $NetBSD: version.mk,v 1.11 2026/09/11 13:58:36 bouyer Exp $
#
# Version number is used by xenkernel418, xentools418 

VERSION=		20260911
XEN_COMMIT=		db29bf7a77831633269293a26e9eeea4cc0d6049
XEN_SHORTCOMMIT=	db29bf7

DIST_SUBDIR=		xen418
DISTNAME=		xen-${XEN_COMMIT}
MASTER_SITES=		-${MASTER_SITE_GITHUB:=xen-project/}xen/archive/${XEN_COMMIT}.tar.gz
DISTFILES=		${DISTNAME}.tar.gz

.if !defined(XENKERNEL)
IPXE_VERSION=		1d1cf74a5e58811822bee4b3da3cff7282fcdfca
IPXE_DIST=		ipxe-${IPXE_VERSION}.tar.gz
DISTFILES+=		${IPXE_DIST}
SITES.${IPXE_DIST}=	-https://github.com/ipxe/ipxe/archive/${IPXE_VERSION}.tar.gz

QEMU_VERSION=		20250521
QEMU_DIST=		qemu-xen-${QEMU_VERSION}
QEMU_DISTFILE=		${QEMU_DIST}.tar.gz
DISTFILES+=		${QEMU_DISTFILE}
SITES.${QEMU_DISTFILE}=	 ${MASTER_SITE_LOCAL}xen418/

QEMUTRAD_VERSION=	3d273dd05e51e5a1ffba3d98c7437ee84e8f8764
QEMUTRAD_DIST=		qemu-xen-traditional-3d273dd
QEMUTRAD_DISTFILE=	${QEMUTRAD_DIST}.tar.gz
DISTFILES+=		${QEMUTRAD_DISTFILE}
SITES.${QEMUTRAD_DISTFILE}=	-https://xenbits.xen.org/gitweb/?p=qemu-xen-traditional.git;a=snapshot;h=${QEMUTRAD_VERSION};sf=tgz

SEABIOS_VERSION=	1.16.2
SEABIOS_DIST=		seabios-${SEABIOS_VERSION}.tar.gz
DISTFILES+=		${SEABIOS_DIST}
SITES.${SEABIOS_DIST}=	-http://xenbits.xen.org/gitweb/?p=seabios.git;a=snapshot;h=refs/tags/rel-${SEABIOS_VERSION};sf=tgz
.endif # !XENKERNEL
