# $NetBSD: Makefile,v 1.1.1.1 2004/07/31 11:27:32 jdolecek Exp $

DISTNAME=		suse_openmotif-${SUSE_VERSION}
CATEGORIES=		emulators
MASTER_SITES=		${MASTER_SITE_SUSE91}
DISTFILES=		${RPMFILES}

MAINTAINER=		tron@NetBSD.org
HOMEPAGE=		http://www.suse.com/
COMMENT=		Linux compatibility package for the Motif library

DEPENDS+=		suse_x11>=${SUSE_VERSION}:../../emulators/suse91_x11

ONLY_FOR_PLATFORM=      NetBSD-*-i386 FreeBSD-*-i386

EXTRACT_ONLY=		# empty
NO_BUILD=		YES
NO_BUILDLINK=		YES
PLIST_SRC=		${WRKDIR}/PLIST_DYNAMIC

RPMFILES=		openmotif-libs-2.2.2-515.${SUSE_ARCH}.rpm

.include "../../emulators/suse91_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
