# $NetBSD: Makefile,v 1.2 2006/06/30 16:20:23 salo Exp $

DISTNAME=		suse_aspell-${SUSE_VERSION}
PKGREVISION=		1
CATEGORIES=		emulators
MASTER_SITES=		${MASTER_SITE_SUSE100}
DISTFILES=		${RPMFILES}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.suse.com/
COMMENT=		Linux compatibility package for Aspell library

.if !defined(USE_NATIVE_LINUX)
DEPENDS+=		suse_base-${SUSE_VERSION}{,nb*}:../../emulators/suse100_base
.endif

EXTRACT_ONLY=		# empty
NO_BUILD=		YES
PLIST_SRC=		${WRKDIR}/PLIST_DYNAMIC

.if exists(Makefile.${MACHINE_ARCH})
.include "Makefile.${MACHINE_ARCH}"
.endif

.include "../../emulators/suse100_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
