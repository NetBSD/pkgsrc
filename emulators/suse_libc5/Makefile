# $NetBSD: Makefile,v 1.30 2005/12/12 14:43:24 joerg Exp $

DISTNAME=		shlibs5
PKGNAME=		suse_libc5-${SUSE_VERSION}
PKGREVISION=		1
CATEGORIES=		emulators
MASTER_SITES=		${MASTER_SITE_SUSE:=a2/}
EXTRACT_SUFX=		.rpm

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.suse.com/
COMMENT=		Linux compatibility package for libc5 binaries

DEPENDS+=		suse_compat>=${SUSE_VERSION}:../../emulators/${SUSE_DIR_PREFIX}_compat

EXTRACT_ONLY=		# empty
NO_BUILD=		YES
PLIST_SRC=		${WRKDIR}/PLIST_DYNAMIC

RPMFILES=		${DISTNAME}${EXTRACT_SUFX}

# force use of SuSE 7.3 base
.include "../../emulators/suse_linux/vars.mk"

.include "../../emulators/suse_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
