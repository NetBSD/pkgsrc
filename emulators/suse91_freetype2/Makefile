# $NetBSD: Makefile,v 1.4 2005/12/12 14:43:23 joerg Exp $

DISTNAME=		suse_freetype2-${SUSE_VERSION}
PKGREVISION=		1
CATEGORIES=		emulators
MASTER_SITES=		${MASTER_SITE_SUSE91}
DISTFILES=		${RPMFILES}

MAINTAINER=		jdolecek@NetBSD.org
HOMEPAGE=		http://www.suse.com/
COMMENT=		Linux compatibility package for FreeType2 library

DEPENDS+=		suse_base>=${SUSE_VERSION}:../../emulators/suse91_base

EXTRACT_ONLY=		# empty
NO_BUILD=		YES
PLIST_SRC=		${WRKDIR}/PLIST_DYNAMIC

RPMFILES=		freetype2-2.1.7-53.6.${SUSE_ARCH}.rpm

.include "../../emulators/suse91_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
