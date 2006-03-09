# $NetBSD: Makefile,v 1.1.1.1 2006/03/09 20:37:05 tonio Exp $

DISTNAME=		suse_x11-${SUSE_VERSION}
CATEGORIES=		emulators
MASTER_SITES=		${MASTER_SITE_SUSE100}
DISTFILES=		${RPMFILES}

MAINTAINER=		tonio@NetBSD.org
HOMEPAGE=		http://www.suse.com/
COMMENT=		Linux compatibility package for X11 binaries

DEPENDS+=		suse_base>=${SUSE_VERSION}:../../emulators/suse100_base

EXTRACT_ONLY=		# empty
NO_BUILD=		YES
PLIST_SRC=		${WRKDIR}/PLIST_DYNAMIC

.if exists(Makefile.${MACHINE_ARCH})
.include "Makefile.${MACHINE_ARCH}"
DISTINFO_FILE=		${.CURDIR}/distinfo.${MACHINE_ARCH}
.endif

.include "../../mk/bsd.prefs.mk"

.include "../../emulators/suse100_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
