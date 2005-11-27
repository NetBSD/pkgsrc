# $NetBSD: Makefile,v 1.8.4.1 2005/11/27 21:28:43 snj Exp $

DISTNAME=		suse_gtk2-${SUSE_VERSION}
PKGREVISION=		4
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

ONLY_FOR_PLATFORM=      NetBSD-*-i386 FreeBSD-*-i386

EXTRACT_ONLY=		# empty
USE_PKGINSTALL=		YES
NO_BUILD=		YES
PLIST_SRC=		${WRKDIR}/PLIST_DYNAMIC

RPMFILES=		atk-1.4.1-124.${SUSE_ARCH}.rpm \
			glib2-2.2.3-117.${SUSE_ARCH}.rpm \
			gtk2-2.2.4-125.10.${SUSE_ARCH}.rpm \
			pango-1.2.5-170.${SUSE_ARCH}.rpm

# Initialize gtk/pango modules.
FILES_SUBST+=		EMULDIR=${EMULDIR}
PLIST_SUBST+=		EMULSUBDIR=${EMULSUBDIR}
INSTALL_EXTRA_TMPL+=	${PKGDIR}/INSTALL

.include "../../emulators/suse91_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
