# $NetBSD: Makefile,v 1.1.1.1 2004/09/02 20:34:08 recht Exp $

DISTNAME=		suse_gtk2-${SUSE_VERSION}
CATEGORIES=		emulators
MASTER_SITES=		${MASTER_SITE_SUSE91}
DISTFILES=		${RPMFILES}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.suse.com/
COMMENT=		Linux compatibility package for GTK2 binaries

DEPENDS+=		suse_fontconfig>=${SUSE_VERSION}:../../emulators/suse91_fontconfig
DEPENDS+=		suse_freetype2>=${SUSE_VERSION}:../../emulators/suse91_freetype2
DEPENDS+=		suse_libtiff>=${SUSE_VERSION}:../../emulators/suse91_libtiff
DEPENDS+=		suse_x11>=${SUSE_VERSION}:../../emulators/suse91_x11

ONLY_FOR_PLATFORM=      NetBSD-*-i386 FreeBSD-*-i386

EXTRACT_ONLY=		# empty
USE_PKGINSTALL=		YES
NO_BUILD=		YES
NO_BUILDLINK=		YES
PLIST_SRC=		${WRKDIR}/PLIST_DYNAMIC

RPMFILES=		atk-1.4.1-124.${SUSE_ARCH}.rpm \
			glib2-2.2.3-117.${SUSE_ARCH}.rpm \
			gtk2-2.2.4-121.${SUSE_ARCH}.rpm \
			pango-1.2.5-170.${SUSE_ARCH}.rpm

# Initialize gtk/pango modules.
FILES_SUBST+=		EMULDIR=${EMULDIR}
INSTALL_EXTRA_TMPL+=	${PKGDIR}/INSTALL
DEINSTALL_EXTRA_TMPL+=	${PKGDIR}/DEINSTALL

.include "../../emulators/suse91_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
