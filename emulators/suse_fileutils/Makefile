# $NetBSD: Makefile,v 1.4 2005/12/12 14:43:24 joerg Exp $

DISTNAME=		suse_fileutils-${SUSE_VERSION}
CATEGORIES=		emulators
MASTER_SITES=		${MASTER_SITE_SUSE:=a1/}

DISTFILES=		${RPMFILES}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.suse.com/
COMMENT=		Linux compatibility package - fileutils

DEPENDS+=		suse_base>=${SUSE_VERSION}:../../emulators/suse_base

EXTRACT_ONLY=		# empty
NO_BUILD=		YES
PLIST_SRC=		${WRKDIR}/PLIST_DYNAMIC

RPMFILES=		fileutils.rpm

.include "../../emulators/suse_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
