# $NetBSD: Makefile,v 1.19 2004/04/14 11:31:10 xtraeme Exp $

DISTNAME=		suse_devel-${SUSE_VERSION}
CATEGORIES=		emulators
PKGREVISION=		2
MASTER_SITES=		${MASTER_SITE_SUSE:=d1/} \
			${MASTER_SITE_SUSE:=d2/} \
			${MASTER_SITE_SUSE_UPD:=d1/}

DISTFILES=		${RPMFILES}

MAINTAINER=		tron@NetBSD.org
HOMEPAGE=		http://www.suse.com/
COMMENT=		Linux compatibility package - development tools

DEPENDS+=		suse_base>=${SUSE_VERSION}:../suse_base

ONLY_FOR_PLATFORM=      NetBSD-*-i386 NetBSD-*-powerpc FreeBSD-*-i386

EXTRACT_ONLY=		# empty
NO_BUILD=		YES
PLIST_SRC=		${WRKDIR}/PLIST_DYNAMIC

RPMFILES=		binutils.rpm cpp.rpm g77.rpm gcc.rpm gpp.rpm make.rpm

.include "../suse_linux/arch.mk"

.if ${SUSE_ARCH} == "i386"
RPMFILES+=      glibc-devel-2.2.4-78.${SUSE_ARCH}.rpm bin86.rpm
.elif ${SUSE_ARCH} == "ppc"
RPMFILES+=      glibc-devel-2.2.4-69.${SUSE_ARCH}.rpm
.else
RPMFILES+=      glibc.rpm
.endif

.include "../suse_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
