# $NetBSD: Makefile,v 1.4 2006/06/06 14:53:06 salo Exp $

DISTNAME=		suse_gtk2-${SUSE_VERSION}
PKGREVISION=		1
CATEGORIES=		emulators
MASTER_SITES=		${MASTER_SITE_SUSE100}
DISTFILES=		${RPMFILES}

MAINTAINER=		tonio@NetBSD.org
HOMEPAGE=		http://www.suse.com/
COMMENT=		Linux compatibility package for GTK2 binaries

DEPENDS+=		suse_fontconfig>=${SUSE_VERSION}:../../emulators/suse100_fontconfig
DEPENDS+=		suse_freetype2>=${SUSE_VERSION}:../../emulators/suse100_freetype2
DEPENDS+=		suse_libjpeg>=${SUSE_VERSION}:../../emulators/suse100_libjpeg
DEPENDS+=		suse_libpng>=${SUSE_VERSION}:../../emulators/suse100_libpng
DEPENDS+=		suse_libtiff>=${SUSE_VERSION}:../../emulators/suse100_libtiff
DEPENDS+=		suse_x11>=${SUSE_VERSION}:../../emulators/suse100_x11

EXTRACT_ONLY=		# empty
NO_BUILD=		YES
PLIST_SRC=		${WRKDIR}/PLIST_DYNAMIC

# Initialize gtk/pango modules.
FILES_SUBST+=		EMULDIR=${EMULDIR:Q}
PLIST_SUBST+=		EMULSUBDIR=${EMULSUBDIR:Q}

.if exists(Makefile.${MACHINE_ARCH})
.include "Makefile.${MACHINE_ARCH}"
.endif

.include "../../emulators/suse100_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
