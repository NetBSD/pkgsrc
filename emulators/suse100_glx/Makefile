# $NetBSD: Makefile,v 1.3 2006/06/30 16:20:23 salo Exp $

DISTNAME=		suse_glx-${SUSE_VERSION}
PKGREVISION=		2
CATEGORIES=		emulators
MASTER_SITES=		${MASTER_SITE_SUSE100}
DISTFILES=		${RPMFILES}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.suse.com/
COMMENT=		Linux compatibility package for the GL library

DEPENDS+=		suse_x11-${SUSE_VERSION}{,nb*}:../../emulators/suse100_x11

EXTRACT_ONLY=		# empty
NO_BUILD=		YES
LIBTOOLIZE_PLIST=	NO
PLIST_SRC=		${WRKDIR}/PLIST_DYNAMIC

.if exists(Makefile.${MACHINE_ARCH})
.include "Makefile.${MACHINE_ARCH}"
.endif

.include "../../emulators/suse100_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
