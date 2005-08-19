# $NetBSD: Makefile,v 1.5 2005/08/19 14:58:57 tron Exp $

DISTNAME=		suse_x11-${SUSE_VERSION}
PKGREVISION=		2
CATEGORIES=		emulators
MASTER_SITES=		${MASTER_SITE_SUSE91}
DISTFILES=		${RPMFILES}

MAINTAINER=		tron@NetBSD.org
HOMEPAGE=		http://www.suse.com/
COMMENT=		Linux compatibility package for X11 binaries

DEPENDS+=		suse_base>=${SUSE_VERSION}:../../emulators/suse91_base

ONLY_FOR_PLATFORM=	NetBSD-[2-9]*-i386 NetBSD-[3-9]*-x86_64 \
			FreeBSD-*-i386

EXTRACT_ONLY=		# empty
NO_BUILD=		YES
PLIST_SRC=		${WRKDIR}/PLIST_DYNAMIC

.if ${MACHINE_ARCH} == "x86_64"
RPMFILES=		XFree86-libs-4.3.99.902-30.${SUSE_ARCH}.rpm
.else
RPMFILES=		XFree86-libs-4.3.99.902-43.42.5.${SUSE_ARCH}.rpm
.endif

.include "../../mk/bsd.prefs.mk"

.include "../../emulators/suse91_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
