# $NetBSD: Makefile,v 1.26 2006/02/05 23:09:04 joerg Exp $

DISTNAME=		suse_devel-${SUSE_VERSION}
CATEGORIES=		emulators
PKGREVISION=		3
MASTER_SITES=		${MASTER_SITE_SUSE:=d1/} \
			${MASTER_SITE_SUSE:=d2/} \
			${MASTER_SITE_SUSE_UPD:=d1/}

DISTFILES=		${RPMFILES}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.suse.com/
COMMENT=		Linux compatibility package - development tools

DEPENDS+=		suse_base>=${SUSE_VERSION}:../../emulators/suse_base

EXTRACT_ONLY=		# empty
NO_BUILD=		YES
PLIST_SRC=		${WRKDIR}/PLIST_DYNAMIC

RPMFILES=		binutils.rpm cpp.rpm g77.rpm gcc.rpm gpp.rpm make.rpm

.include "../../emulators/suse_linux/arch.mk"

.if ${SUSE_ARCH} == "i386"
RPMFILES+=      glibc-devel-2.2.4-78.${SUSE_ARCH}.rpm bin86.rpm
.elif ${SUSE_ARCH} == "ppc"
RPMFILES+=      glibc-devel-2.2.4-69.${SUSE_ARCH}.rpm
.else
RPMFILES+=      glibc.rpm
.endif

.include "../../emulators/suse_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
