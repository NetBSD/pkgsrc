# $NetBSD: Makefile,v 1.26 2006/05/28 14:33:20 joerg Exp $

DISTNAME=		compat
PKGNAME=		suse_${DISTNAME}-${SUSE_VERSION}
PKGREVISION=		2
CATEGORIES=		emulators
MASTER_SITES=		${MASTER_SITE_SUSE:=a1/}
EXTRACT_SUFX=		.rpm

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.suse.com/
COMMENT=		Linux compatibility package with old shared libraries

DEPENDS+=		suse_base>=${SUSE_VERSION}:../../emulators/suse_base

EXTRACT_ONLY=		# empty
NO_BUILD=		YES
PLIST_SRC=		${WRKDIR}/PLIST_DYNAMIC

RPMFILES=		${DISTNAME}${EXTRACT_SUFX}

.include "../../emulators/suse_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
