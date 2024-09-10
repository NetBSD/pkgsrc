# $NetBSD: version.mk,v 1.3 2024/09/10 12:40:14 bouyer Exp $
#
# Version number is used by xenkernel418, xentools418 and xenstoretools

VERSION=		20240909
XEN_COMMIT=		bd51e573a730efc569646379cd59ccba967cde97
XEN_SHORTCOMMIT=	bd51e57

DIST_SUBDIR=		xen418
DISTNAME=		xen-${XEN_SHORTCOMMIT}
MASTER_SITES=		-https://xenbits.xen.org/gitweb/?p=xen.git;a=snapshot;h=${XEN_COMMIT};sf=tgz
DISTFILES=		${DISTNAME}.tar.gz

.if !defined(XENKERNEL)
IPXE_VERSION=		1d1cf74a5e58811822bee4b3da3cff7282fcdfca
IPXE_DIST=		ipxe-${IPXE_VERSION}.tar.gz
DISTFILES+=		${IPXE_DIST}
SITES.${IPXE_DIST}=	-https://github.com/ipxe/ipxe/archive/${IPXE_VERSION}.tar.gz

QEMU_VERSION=		${VERSION}
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
