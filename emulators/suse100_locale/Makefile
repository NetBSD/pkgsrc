# $NetBSD: Makefile,v 1.1.1.1 2006/03/13 10:25:35 tonio Exp $

DISTNAME=		suse_locale-${SUSE_VERSION}
CATEGORIES=		emulators
MASTER_SITES=		${MASTER_SITE_SUSE100}
DISTFILES=		${RPMFILES}

MAINTAINER=		tonio@NetBSD.org
HOMEPAGE=		http://www.suse.com/
COMMENT=		Locale files for the Linux compatibility package

DEPENDS+=		suse_base>=${SUSE_VERSION}:../../emulators/suse100_base

CONFLICTS=		linux-locale-[0-9]*

EXTRACT_ONLY=		# empty
NO_BUILD=		YES
PLIST_SRC=		${WRKDIR}/PLIST_DYNAMIC

.if exists(Makefile.${MACHINE_ARCH})
.include "Makefile.${MACHINE_ARCH}"
DISTINFO_FILE=		${.CURDIR}/distinfo.${MACHINE_ARCH}
.endif

.include "../../emulators/suse100_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
