# $NetBSD: Makefile,v 1.4 2005/04/11 21:45:45 tv Exp $

DISTNAME=		suse_openmotif-${SUSE_VERSION}
PKGREVISION=		1
CATEGORIES=		emulators
MASTER_SITES=		${MASTER_SITE_SUSE91}
DISTFILES=		${RPMFILES}

MAINTAINER=		jdolecek@NetBSD.org
HOMEPAGE=		http://www.suse.com/
COMMENT=		Linux compatibility package for the Motif library

DEPENDS+=		suse_x11>=${SUSE_VERSION}:../../emulators/suse91_x11

ONLY_FOR_PLATFORM=      NetBSD-*-i386 FreeBSD-*-i386

EXTRACT_ONLY=		# empty
NO_BUILD=		YES
PLIST_SRC=		${WRKDIR}/PLIST_DYNAMIC

RPMFILES=		openmotif-libs-2.2.2-515.${SUSE_ARCH}.rpm \
			openmotif21-libs-2.1.30MLI4-115.${SUSE_ARCH}.rpm

.include "../../emulators/suse91_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
