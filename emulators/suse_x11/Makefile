# $NetBSD: Makefile,v 1.18 2002/04/07 17:00:13 wiz Exp $

DISTNAME=		suse_x11-${SUSE_VERSION}
PKGREVISION=		2
CATEGORIES=		emulators
MASTER_SITES=		${MASTER_SITE_SUSE:=x1/}
DISTFILES=		${RPMFILES}

MAINTAINER=		tron@netbsd.org
HOMEPAGE=		http://www.suse.com/
COMMENT=		Linux compatibility package for X11 binaries

DEPENDS+=		suse_base>=${SUSE_VERSION}:../suse_base

ONLY_FOR_PLATFORM=      NetBSD-*-i386

EXTRACT_ONLY=		# empty
NO_BUILD=		YES
PLIST_SRC=		${WRKDIR}/PLIST_DYNAMIC

RPMFILES=		xshared.rpm

.include "../../mk/bsd.prefs.mk"

# directory appeared in XFree86 4.*
# if it is missing, we are using XFree86 3.* and need some additional files
.if !exists(${X11BASE}/lib/X11/locale/common)
RPMFILES+=		xf86.rpm
RPMIGNOREPATH=		usr/X11R6/bin usr/X11R6/include \
			usr/X11R6/lib/X11/app-defaults \
			usr/X11R6/lib/X11/doc usr/X11R6/lib/X11/fonts \
			usr/X11R6/lib/X11/x11perfcomp
.endif

.include "../suse_linux/Makefile.common"
