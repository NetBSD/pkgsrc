# $NetBSD: Makefile,v 1.8 2006/02/05 23:09:03 joerg Exp $

DISTNAME=		suse_aspell-${SUSE_VERSION}
PKGREVISION=		2
CATEGORIES=		emulators
MASTER_SITES=		${MASTER_SITE_SUSE91}
DISTFILES=		${RPMFILES}

MAINTAINER=		jdolecek@NetBSD.org
HOMEPAGE=		http://www.suse.com/
COMMENT=		Linux compatibility package for Aspell library

.if !defined(USE_NATIVE_LINUX)
DEPENDS+=		suse_base>=${SUSE_VERSION}:../../emulators/suse91_base
.endif

EXTRACT_ONLY=		# empty
NO_BUILD=		YES
PLIST_SRC=		${WRKDIR}/PLIST_DYNAMIC

.if exists(Makefile.${MACHINE_ARCH})
.include "Makefile.${MACHINE_ARCH}"
.endif

.include "../../emulators/suse_linux/Makefile.application"
.include "../../mk/bsd.pkg.mk"
