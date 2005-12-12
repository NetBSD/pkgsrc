# $NetBSD: Makefile,v 1.5 2005/12/12 14:43:23 joerg Exp $

DISTNAME=		suse_aspell-${SUSE_VERSION}
PKGREVISION=		1
CATEGORIES=		emulators
MASTER_SITES=		${MASTER_SITE_SUSE91}
DISTFILES=		${RPMFILES}

MAINTAINER=		jdolecek@NetBSD.org
HOMEPAGE=		http://www.suse.com/
COMMENT=		Linux compatibility package for Aspell library

RPMFILES=		aspell-0.50.5-38.4.${SUSE_ARCH}.rpm

.include "../../emulators/suse_linux/Makefile.application"

.if !defined(USE_NATIVE_LINUX)
DEPENDS+=		suse_base>=${SUSE_VERSION}:../../emulators/suse91_base
.endif

ONLY_FOR_PLATFORM=      *-*-i386

EXTRACT_ONLY=		# empty
NO_BUILD=		YES
PLIST_SRC=		${WRKDIR}/PLIST_DYNAMIC

.include "../../mk/bsd.pkg.mk"
