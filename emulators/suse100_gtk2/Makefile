# $NetBSD: Makefile,v 1.8 2007/04/19 15:30:21 xtraeme Exp $

DISTNAME=		suse_gtk2-${SUSE_VERSION}
PKGREVISION=		3
CATEGORIES=		emulators
MASTER_SITES=		${MASTER_SITE_SUSE100}
DISTFILES=		${RPMFILES}

MAINTAINER=		tonio@NetBSD.org
HOMEPAGE=		http://www.suse.com/
COMMENT=		Linux compatibility package for GTK2 binaries

DEPENDS+=		suse_fontconfig-${SUSE_VERSION}{,nb*}:../../emulators/suse100_fontconfig
DEPENDS+=		suse_freetype2-${SUSE_VERSION}{,nb*}:../../emulators/suse100_freetype2
DEPENDS+=		suse_libjpeg-${SUSE_VERSION}{,nb*}:../../emulators/suse100_libjpeg
DEPENDS+=		suse_libpng-${SUSE_VERSION}{,nb*}:../../emulators/suse100_libpng
DEPENDS+=		suse_libtiff-${SUSE_VERSION}{,nb*}:../../emulators/suse100_libtiff
DEPENDS+=		suse_x11-${SUSE_VERSION}{,nb*}:../../emulators/suse100_x11

EXTRACT_ONLY=		# empty
NO_BUILD=		YES
PLIST_SRC=		${WRKDIR}/PLIST_DYNAMIC

# Initialize gtk/pango modules.
FILES_SUBST+=		EMULDIR=${EMULDIR:Q}
FILES_SUBST+=		BINSUFFIX=${BINSUFFIX:Q}
PLIST_SUBST+=		EMULSUBDIR=${EMULSUBDIR:Q}

SUSE_INCLUDE_MAKEFILE_ARCH=	yes

.include "../../emulators/suse100_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
