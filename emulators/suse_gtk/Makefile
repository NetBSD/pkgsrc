# $NetBSD: Makefile,v 1.10 2003/07/17 21:36:09 grant Exp $

DISTNAME=		suse_gtk-${SUSE_VERSION}
CATEGORIES=		emulators
MASTER_SITES=		${MASTER_SITE_SUSE:=gra1/} \
			${MASTER_SITE_SUSE:=xdev1/}
DISTFILES=		${RPMFILES}

MAINTAINER=		tron@NetBSD.org
HOMEPAGE=		http://www.suse.com/
COMMENT=		Linux compatibility package for GTK binaries

DEPENDS+=		suse_x11>=${SUSE_VERSION}:../suse_x11

ONLY_FOR_PLATFORM=      NetBSD-*-i386 NetBSD-*-powerpc

EXTRACT_ONLY=		# empty
NO_BUILD=		YES
PLIST_SRC=		${WRKDIR}/PLIST_DYNAMIC

RPMFILES=		glib.rpm gtk.rpm

.include "../suse_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
