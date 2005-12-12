# $NetBSD: Makefile,v 1.3 2005/12/12 14:43:23 joerg Exp $

DISTNAME=		suse_fontconfig-${SUSE_VERSION}
CATEGORIES=		emulators
MASTER_SITES=		${MASTER_SITE_SUSE91}
DISTFILES=		${RPMFILES}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.suse.com/
COMMENT=		Linux compatibility package for fontconfig binaries

DEPENDS+=		suse_expat>=${SUSE_VERSION}:../../emulators/suse91_expat

EXTRACT_ONLY=		# empty
NO_BUILD=		YES
PLIST_SRC=		${WRKDIR}/PLIST_DYNAMIC

RPMFILES=		fontconfig-2.2.92.20040221-28.${SUSE_ARCH}.rpm

.include "../../emulators/suse91_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
