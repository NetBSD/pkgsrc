# $NetBSD: Makefile,v 1.22 2003/09/18 16:25:24 jmmv Exp $

DISTNAME=		shlibs5
PKGNAME=		suse_libc5-${SUSE_VERSION}
CATEGORIES=		emulators
MASTER_SITES=		${MASTER_SITE_SUSE:=a2/}
EXTRACT_SUFX=		.rpm

MAINTAINER=		tron@NetBSD.org
HOMEPAGE=		http://www.suse.com/
COMMENT=		Linux compatibility package for libc5 binaries

DEPENDS+=		suse_compat>=${SUSE_VERSION}:../../emulators/suse_compat

CONFLICTS+=		mozilla-bin-[0-9]*
CONFLICTS+=		phoenix-bin-[0-9]*

ONLY_FOR_PLATFORM=      NetBSD-*-i386

EXTRACT_ONLY=		# empty
NO_BUILD=		YES
PLIST_SRC=		${WRKDIR}/PLIST_DYNAMIC

RPMFILES=		${DISTNAME}${EXTRACT_SUFX}

.include "../../emulators/suse_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
