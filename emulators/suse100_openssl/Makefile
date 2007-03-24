# $NetBSD: Makefile,v 1.4 2007/03/24 21:52:51 salo Exp $

DISTNAME=		suse_openssl-${SUSE_VERSION}
PKGREVISION=		3
CATEGORIES=		emulators
MASTER_SITES=		${MASTER_SITE_SUSE100}
DISTFILES=		${RPMFILES}

MAINTAINER=		markd@NetBSD.org
HOMEPAGE=		http://www.suse.com/
COMMENT=		Linux compatibility package for the OpenSSL library

DEPENDS+=		suse_base-${SUSE_VERSION}{,nb*}:../../emulators/suse100_base

EXTRACT_ONLY=		# empty
NO_BUILD=		YES
PLIST_SRC=		${WRKDIR}/PLIST_DYNAMIC

.if exists(Makefile.${MACHINE_ARCH})
.include "Makefile.${MACHINE_ARCH}"
.endif

.include "../../emulators/suse100_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
