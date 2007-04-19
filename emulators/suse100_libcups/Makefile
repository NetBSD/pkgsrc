# $NetBSD: Makefile,v 1.4 2007/04/19 15:30:21 xtraeme Exp $

DISTNAME=		suse_libcups-${SUSE_VERSION}
PKGREVISION=		2
CATEGORIES=		emulators
MASTER_SITES=		${MASTER_SITE_SUSE100}
DISTFILES=		${RPMFILES}

MAINTAINER=		markd@NetBSD.org
HOMEPAGE=		http://www.suse.com/
COMMENT=		Linux compatibility package for the Cups library

DEPENDS+=		suse_openssl-${SUSE_VERSION}{,nb*}:../../emulators/suse100_openssl

EXTRACT_ONLY=		# empty
NO_BUILD=		YES
PLIST_SRC=		${WRKDIR}/PLIST_DYNAMIC

SUSE_INCLUDE_MAKEFILE_ARCH=	yes

.include "../../emulators/suse100_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
