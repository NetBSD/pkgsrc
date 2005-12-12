# $NetBSD: Makefile,v 1.18 2005/12/12 14:43:25 joerg Exp $

DISTNAME=		libpng
PKGREVISION=		1
PKGNAME=		suse_${DISTNAME}-${SUSE_VERSION}
CATEGORIES=		emulators
MASTER_SITES=		${MASTER_SITE_SUSE_UPD:=gra1/}
DISTFILES=		${RPMFILES}
EXTRACT_SUFX=		.rpm

MAINTAINER=		jdolecek@NetBSD.org
HOMEPAGE=		http://www.suse.com/
COMMENT=		Linux compatibility package for the PNG library

DEPENDS+=		suse_base>=${SUSE_VERSION}:../../emulators/suse_base

EXTRACT_ONLY=		# empty
NO_BUILD=		YES
PLIST_SRC=		${WRKDIR}/PLIST_DYNAMIC

.include "../../emulators/suse_linux/arch.mk"

.if ${SUSE_ARCH} == "i386"
RPMFILES=		${DISTNAME}-2.1.0.12-160.${SUSE_ARCH}${EXTRACT_SUFX}
.elif ${SUSE_ARCH} == "ppc"
RPMFILES=		${DISTNAME}-2.1.0.12-131.${SUSE_ARCH}${EXTRACT_SUFX}
.else
RPMFILES=		${DISTNAME}${EXTRACT_SUFX}
.endif

.include "../../emulators/suse_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
