# $NetBSD: Makefile,v 1.15 2003/07/17 21:36:18 grant Exp $

DISTNAME=		xforms
PKGNAME=		suse_${DISTNAME}-${SUSE_VERSION}
CATEGORIES=		emulators
MASTER_SITES=		${MASTER_SITE_SUSE:=pay3/}
EXTRACT_SUFX=		.rpm

MAINTAINER=		tron@NetBSD.org
HOMEPAGE=		http://www.suse.com/
COMMENT=		Linux compatibility package for xforms binaries

DEPENDS+=		suse_x11>=${SUSE_VERSION}:../suse_x11

ONLY_FOR_PLATFORM=      NetBSD-*-i386 NetBSD-*-powerpc

EXTRACT_ONLY=		# empty
NO_BUILD=		YES
PLIST_SRC=		${WRKDIR}/PLIST_DYNAMIC

RPMFILES=		${DISTNAME}${EXTRACT_SUFX}

.include "../suse_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
