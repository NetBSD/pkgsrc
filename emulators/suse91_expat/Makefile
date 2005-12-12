# $NetBSD: Makefile,v 1.4 2005/12/12 14:43:23 joerg Exp $

DISTNAME=		suse_expat-${SUSE_VERSION}
PKGREVISION=		1
CATEGORIES=		emulators
MASTER_SITES=		${MASTER_SITE_SUSE91}
DISTFILES=		${RPMFILES}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.suse.com/
COMMENT=		Linux compatibility package for expat binaries

DEPENDS+=		suse_base>=${SUSE_VERSION}:../../emulators/suse91_base

EXTRACT_ONLY=		# empty
NO_BUILD=		YES
LIBTOOLIZE_PLIST=	NO
PLIST_SRC=		${WRKDIR}/PLIST_DYNAMIC

RPMFILES=		expat-1.95.7-37.${SUSE_ARCH}.rpm

.include "../../emulators/suse91_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
