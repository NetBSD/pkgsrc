# $NetBSD: Makefile,v 1.1.1.1 2006/04/18 14:08:33 salo Exp $

DISTNAME=		suse_aspell-${SUSE_VERSION}
CATEGORIES=		emulators
MASTER_SITES=		${MASTER_SITE_SUSE100}
DISTFILES=		${RPMFILES}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.suse.com/
COMMENT=		Linux compatibility package for Aspell library

.if !defined(USE_NATIVE_LINUX)
DEPENDS+=		suse_base>=${SUSE_VERSION}:../../emulators/suse100_base
.endif

EXTRACT_ONLY=		# empty
NO_BUILD=		YES
PLIST_SRC=		${WRKDIR}/PLIST_DYNAMIC

.if exists(Makefile.${MACHINE_ARCH})
.include "Makefile.${MACHINE_ARCH}"
.endif

.include "../../emulators/suse100_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
