# $NetBSD: Makefile,v 1.13 2006/03/04 21:29:36 jlam Exp $

DISTNAME=		freetype2
PKGNAME=		suse_${DISTNAME}-${SUSE_VERSION}
CATEGORIES=		emulators
PKGREVISION=		2
MASTER_SITES=		${MASTER_SITE_SUSE:=gra1/} \
			${MASTER_SITE_SUSE_UPD:=gra1/}
DISTFILES=		${RPMFILES}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.suse.com/
COMMENT=		Linux compatibility package for the FreeType2 library

DEPENDS+=		suse_base>=${SUSE_VERSION}:../../emulators/suse_base

NO_BUILD=		YES
EXTRACT_ONLY=		# empty
PLIST_SRC=		${WRKDIR}/PLIST_DYNAMIC

RPMFILES+=      	freetype2-2.0.4-52.${SUSE_ARCH}.rpm

.include "../../emulators/suse_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
