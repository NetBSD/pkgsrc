# $NetBSD: Makefile,v 1.6 2005/12/12 14:43:23 joerg Exp $

DISTNAME=		suse_compat-${SUSE_VERSION}
CATEGORIES=		emulators
MASTER_SITES=		${MASTER_SITE_SUSE91}
DISTFILES=		${RPMFILES}

MAINTAINER=		tron@NetBSD.org
HOMEPAGE=		http://www.suse.com/
COMMENT=		Linux compatibility package with old shared libraries

DEPENDS+=		suse_base>=${SUSE_VERSION}:../../emulators/suse91_base

EXTRACT_ONLY=		# empty
NO_BUILD=		YES
PLIST_SRC=		${WRKDIR}/PLIST_DYNAMIC

RPMFILES=		compat-2004.4.2-3.${SUSE_ARCH}.rpm

.include "../../emulators/suse91_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
