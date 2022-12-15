# $NetBSD: version.mk,v 1.3 2022/12/15 13:24:44 bouyer Exp $
#
# Version number is used by xentools415 and xenstoretools

VERSION=	4.15.4

DIST_SUBDIR=		xen415
DISTNAME=		xen-${VERSION}
MASTER_SITES=		https://downloads.xenproject.org/release/xen/${VERSION}/
DISTFILES=		${DISTNAME}.tar.gz

IPXE_VERSION=		988d2c13cdf0f0b4140685af35ced70ac5b3283c
IPXE_DIST=		ipxe-${IPXE_VERSION}.tar.gz
DISTFILES+=		${IPXE_DIST}
SITES.${IPXE_DIST}=	-https://github.com/ipxe/ipxe/archive/${IPXE_VERSION}.tar.gz

SEABIOS_VERSION=	1.14.0
SEABIOS_DIST=		seabios-${SEABIOS_VERSION}.tar.gz
DISTFILES+=		${SEABIOS_DIST}
SITES.${SEABIOS_DIST}=	-http://xenbits.xen.org/gitweb/?p=seabios.git;a=snapshot;h=refs/tags/rel-${SEABIOS_VERSION};sf=tgz
