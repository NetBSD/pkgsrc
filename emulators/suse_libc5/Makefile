# $NetBSD: Makefile,v 1.19 2003/03/26 04:05:47 jschauma Exp $

DISTNAME=		shlibs5
PKGNAME=		suse_libc5-${SUSE_VERSION}
CATEGORIES=		emulators
MASTER_SITES=		${MASTER_SITE_SUSE:=a2/}
EXTRACT_SUFX=		.rpm

MAINTAINER=		tron@netbsd.org
HOMEPAGE=		http://www.suse.com/
COMMENT=		Linux compatibility package for libc5 binaries

DEPENDS+=		suse_compat>=${SUSE_VERSION}:../suse_compat

ONLY_FOR_PLATFORM=      NetBSD-*-i386

EXTRACT_ONLY=		# empty
NO_BUILD=		YES
PLIST_SRC=		${WRKDIR}/PLIST_DYNAMIC

RPMFILES=		${DISTNAME}${EXTRACT_SUFX}

.include "../suse_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
