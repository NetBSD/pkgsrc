# $NetBSD: Makefile,v 1.27 2005/04/02 20:37:31 jdolecek Exp $

DISTNAME=		shlibs5
PKGNAME=		suse_libc5-${SUSE_VERSION}
PKGREVISION=		1
CATEGORIES=		emulators
MASTER_SITES=		${MASTER_SITE_SUSE:=a2/}
EXTRACT_SUFX=		.rpm

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.suse.com/
COMMENT=		Linux compatibility package for libc5 binaries

DEPENDS+=		suse_compat>=${SUSE_VERSION}:../../emulators/${SUSE_DIR_PREFIX}_compat

ONLY_FOR_PLATFORM=      NetBSD-*-i386 FreeBSD-*-i386

EXTRACT_ONLY=		# empty
NO_BUILD=		YES
NO_BUILDLINK=		YES
PLIST_SRC=		${WRKDIR}/PLIST_DYNAMIC

RPMFILES=		${DISTNAME}${EXTRACT_SUFX}

.include "../../emulators/suse_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
