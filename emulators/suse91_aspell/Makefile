# $NetBSD: Makefile,v 1.3 2005/04/11 21:45:44 tv Exp $

DISTNAME=		suse_aspell-${SUSE_VERSION}
CATEGORIES=		emulators
MASTER_SITES=		${MASTER_SITE_SUSE91}
DISTFILES=		${RPMFILES}

MAINTAINER=		jdolecek@NetBSD.org
HOMEPAGE=		http://www.suse.com/
COMMENT=		Linux compatibility package for Aspell library

DEPENDS+=		suse_base>=${SUSE_VERSION}:../../emulators/suse91_base

ONLY_FOR_PLATFORM=      NetBSD-*-i386 FreeBSD-*-i386

EXTRACT_ONLY=		# empty
NO_BUILD=		YES
PLIST_SRC=		${WRKDIR}/PLIST_DYNAMIC

RPMFILES=		aspell-0.50.5-35.${SUSE_ARCH}.rpm

.include "../../emulators/suse91_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
