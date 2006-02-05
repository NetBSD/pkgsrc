# $NetBSD: Makefile,v 1.14 2006/02/05 23:09:03 joerg Exp $

DISTNAME=		suse_gtk2-${SUSE_VERSION}
PKGREVISION=		5
CATEGORIES=		emulators
MASTER_SITES=		${MASTER_SITE_SUSE91}
DISTFILES=		${RPMFILES}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.suse.com/
COMMENT=		Linux compatibility package for GTK2 binaries

DEPENDS+=		suse_fontconfig>=${SUSE_VERSION}:../../emulators/suse91_fontconfig
DEPENDS+=		suse_freetype2>=${SUSE_VERSION}:../../emulators/suse91_freetype2
DEPENDS+=		suse_libjpeg>=${SUSE_VERSION}:../../emulators/suse91_libjpeg
DEPENDS+=		suse_libpng>=${SUSE_VERSION}:../../emulators/suse91_libpng
DEPENDS+=		suse_libtiff>=${SUSE_VERSION}:../../emulators/suse91_libtiff
DEPENDS+=		suse_x11>=${SUSE_VERSION}:../../emulators/suse91_x11

EXTRACT_ONLY=		# empty
NO_BUILD=		YES
PLIST_SRC=		${WRKDIR}/PLIST_DYNAMIC

# Initialize gtk/pango modules.
FILES_SUBST+=		EMULDIR=${EMULDIR:Q}
PLIST_SUBST+=		EMULSUBDIR=${EMULSUBDIR:Q}
INSTALL_EXTRA_TMPL+=	${PKGDIR}/INSTALL

.if exists(Makefile.${MACHINE_ARCH})
.include "Makefile.${MACHINE_ARCH}"
.endif

.include "../../emulators/suse91_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
