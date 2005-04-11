# $NetBSD: Makefile,v 1.15 2005/04/11 21:45:45 tv Exp $

DISTNAME=		suse_gtk-${SUSE_VERSION}
CATEGORIES=		emulators
MASTER_SITES=		${MASTER_SITE_SUSE:=gra1/} \
			${MASTER_SITE_SUSE:=xdev1/}
DISTFILES=		${RPMFILES}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.suse.com/
COMMENT=		Linux compatibility package for GTK binaries

DEPENDS+=		suse_x11>=${SUSE_VERSION}:../../emulators/suse_x11

ONLY_FOR_PLATFORM=      NetBSD-*-i386 NetBSD-*-powerpc FreeBSD-*-i386

EXTRACT_ONLY=		# empty
NO_BUILD=		YES
PLIST_SRC=		${WRKDIR}/PLIST_DYNAMIC

RPMFILES=		glib.rpm gtk.rpm

.include "../../emulators/suse_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
