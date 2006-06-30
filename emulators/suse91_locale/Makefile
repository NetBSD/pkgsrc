# $NetBSD: Makefile,v 1.7 2006/06/30 15:37:22 salo Exp $

DISTNAME=		suse_locale-${SUSE_VERSION}
PKGREVISION=		2
CATEGORIES=		emulators
MASTER_SITES=		${MASTER_SITE_SUSE91}
DISTFILES=		${RPMFILES}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.suse.com/
COMMENT=		Locale files for the Linux compatibility package

DEPENDS+=		suse_base-${SUSE_VERSION}{,nb*}:../../emulators/suse91_base

CONFLICTS=		linux-locale-[0-9]*

EXTRACT_ONLY=		# empty
NO_BUILD=		YES
PLIST_SRC=		${WRKDIR}/PLIST_DYNAMIC

.if exists(Makefile.${MACHINE_ARCH})
.include "Makefile.${MACHINE_ARCH}"
.endif

.include "../../emulators/suse91_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
