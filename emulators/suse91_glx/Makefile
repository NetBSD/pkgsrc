# $NetBSD: Makefile,v 1.7 2006/02/05 23:09:03 joerg Exp $

DISTNAME=		suse_glx-${SUSE_VERSION}
PKGREVISION=		1
CATEGORIES=		emulators
MASTER_SITES=		${MASTER_SITE_SUSE91}
DISTFILES=		${RPMFILES}

MAINTAINER=		jdolecek@NetBSD.org
HOMEPAGE=		http://www.suse.com/
COMMENT=		Linux compatibility package for the GL library

DEPENDS+=		suse_base>=${SUSE_VERSION}:../../emulators/suse91_base
DEPENDS+=		suse_x11>=${SUSE_VERSION}:../../emulators/suse91_x11

EXTRACT_ONLY=		# empty
NO_BUILD=		YES
LIBTOOLIZE_PLIST=	NO
PLIST_SRC=		${WRKDIR}/PLIST_DYNAMIC

.if exists(Makefile.${MACHINE_ARCH})
.include "Makefile.${MACHINE_ARCH}"
.endif

.include "../../emulators/suse91_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
