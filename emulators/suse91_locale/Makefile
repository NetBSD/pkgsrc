# $NetBSD: Makefile,v 1.2 2005/04/11 21:45:45 tv Exp $

DISTNAME=		suse_locale-${SUSE_VERSION}
CATEGORIES=		emulators
MASTER_SITES=		${MASTER_SITE_SUSE91}
DISTFILES=		${RPMFILES}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.suse.com/
COMMENT=		Locale files for the Linux compatibility package

DEPENDS+=		suse_base>=${SUSE_VERSION}:../../emulators/suse91_base

CONFLICTS=		linux-locale-[0-9]*

ONLY_FOR_PLATFORM=      NetBSD-*-i386 FreeBSD-*-i386

EXTRACT_ONLY=		# empty
NO_BUILD=		YES
PLIST_SRC=		${WRKDIR}/PLIST_DYNAMIC

RPMFILES=		glibc-locale-2.3.3-98.${SUSE_ARCH}.rpm

.include "../../emulators/suse91_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
