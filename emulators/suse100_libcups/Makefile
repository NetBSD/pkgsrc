# $NetBSD: Makefile,v 1.1.1.1 2006/06/11 13:29:09 markd Exp $

DISTNAME=		suse_libcups-${SUSE_VERSION}
CATEGORIES=		emulators
MASTER_SITES=		${MASTER_SITE_SUSE100}
DISTFILES=		${RPMFILES}

MAINTAINER=		markd@NetBSD.org
HOMEPAGE=		http://www.suse.com/
COMMENT=		Linux compatibility package for the Cups library

DEPENDS+=		suse_base>=${SUSE_VERSION}:../../emulators/suse100_base
DEPENDS+=		suse_openssl>=${SUSE_VERSION}:../../emulators/suse100_openssl

EXTRACT_ONLY=		# empty
NO_BUILD=		YES
PLIST_SRC=		${WRKDIR}/PLIST_DYNAMIC

.if exists(Makefile.${MACHINE_ARCH})
.include "Makefile.${MACHINE_ARCH}"
.endif

.include "../../emulators/suse100_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
