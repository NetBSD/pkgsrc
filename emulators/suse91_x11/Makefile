# $NetBSD: Makefile,v 1.7 2005/12/12 14:43:24 joerg Exp $

DISTNAME=		suse_x11-${SUSE_VERSION}
PKGREVISION=		3
CATEGORIES=		emulators
MASTER_SITES=		${MASTER_SITE_SUSE91}
DISTFILES=		${RPMFILES}

MAINTAINER=		tron@NetBSD.org
HOMEPAGE=		http://www.suse.com/
COMMENT=		Linux compatibility package for X11 binaries

DEPENDS+=		suse_base>=${SUSE_VERSION}:../../emulators/suse91_base

EXTRACT_ONLY=		# empty
NO_BUILD=		YES
PLIST_SRC=		${WRKDIR}/PLIST_DYNAMIC

RPMFILES=		XFree86-libs-4.3.99.902-43.42.5.${SUSE_ARCH}.rpm

.include "../../mk/bsd.prefs.mk"

.include "../../emulators/suse91_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
