# $NetBSD: Makefile,v 1.3 2005/05/15 16:44:33 jdolecek Exp $

DISTNAME=		suse_glx-${SUSE_VERSION}
PKGREVISION=		# empty
CATEGORIES=		emulators
MASTER_SITES=		${MASTER_SITE_SUSE91}
DISTFILES=		${RPMFILES}

MAINTAINER=		jdolecek@NetBSD.org
HOMEPAGE=		http://www.suse.com/
COMMENT=		Linux compatibility package for the GL library

DEPENDS+=		suse_base>=${SUSE_VERSION}:../../emulators/suse91_base
DEPENDS+=		suse_x11>=${SUSE_VERSION}:../../emulators/suse91_x11

ONLY_FOR_PLATFORM=      NetBSD-*-i386 FreeBSD-*-i386

EXTRACT_ONLY=		# empty
NO_BUILD=		YES
LIBTOOLIZE_PLIST=	NO
PLIST_SRC=		${WRKDIR}/PLIST_DYNAMIC

# the -devel version is necessary for libGL.so et.al. symlinks only
RPMFILES=		XFree86-Mesa-4.3.99.902-40.${SUSE_ARCH}.rpm \
			XFree86-Mesa-devel-4.3.99.902-40.${SUSE_ARCH}.rpm

.include "../../emulators/suse91_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
