# $NetBSD: Makefile,v 1.9 2006/02/05 23:09:03 joerg Exp $

DISTNAME=		suse_libpng-${SUSE_VERSION}
PKGREVISION=		4
CATEGORIES=		emulators
MASTER_SITES=		${MASTER_SITE_SUSE91}
DISTFILES=		${RPMFILES}

MAINTAINER=		jdolecek@NetBSD.org
HOMEPAGE=		http://www.suse.com/
COMMENT=		Linux compatibility package for the PNG library

DEPENDS+=		suse_base>=${SUSE_VERSION}:../../emulators/suse91_base

EXTRACT_ONLY=		# empty
NO_BUILD=		YES
PLIST_SRC=		${WRKDIR}/PLIST_DYNAMIC

.if exists(Makefile.${MACHINE_ARCH})
.include "Makefile.${MACHINE_ARCH}"
.endif

.include "../../emulators/suse91_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
