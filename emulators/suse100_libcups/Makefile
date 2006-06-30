# $NetBSD: Makefile,v 1.2 2006/06/30 16:20:23 salo Exp $

DISTNAME=		suse_libcups-${SUSE_VERSION}
PKGREVISION=		1
CATEGORIES=		emulators
MASTER_SITES=		${MASTER_SITE_SUSE100}
DISTFILES=		${RPMFILES}

MAINTAINER=		markd@NetBSD.org
HOMEPAGE=		http://www.suse.com/
COMMENT=		Linux compatibility package for the Cups library

DEPENDS+=		suse_openssl-${SUSE_VERSION}{,nb*}:../../emulators/suse100_openssl

EXTRACT_ONLY=		# empty
NO_BUILD=		YES
PLIST_SRC=		${WRKDIR}/PLIST_DYNAMIC

.if exists(Makefile.${MACHINE_ARCH})
.include "Makefile.${MACHINE_ARCH}"
.endif

.include "../../emulators/suse100_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
