# $NetBSD: Makefile,v 1.4 2003/07/17 21:35:52 grant Exp $

DISTNAME=		suse_gtk-${SUSE_VERSION}
PKGREVISION=		1
CATEGORIES=		emulators
MASTER_SITES=		${MASTER_SITE_SUSE:=gra1/}
DISTFILES=		${RPMFILES}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.suse.com/
COMMENT=		Linux compatibility package for GTK binaries

DEPENDS+=		suse_x11-${SUSE_VERSION}*:../suse64_x11

ONLY_FOR_PLATFORM=      NetBSD-*-i386

EXTRACT_ONLY=		# empty
NO_BUILD=		yes
PLIST_SRC=		${WRKDIR}/PLIST_DYNAMIC

RPMFILES=		glib.rpm gtk.rpm

.include "../suse64_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
