# $NetBSD: Makefile,v 1.2 2000/12/16 22:37:31 tron Exp $

DISTNAME=		suse_gtk-6.3
CATEGORIES=		emulators
MASTER_SITES=		${MASTER_SITE_SUSE:=gra2/}
DISTFILES=		${RPMFILES}

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.suse.com/

DEPENDS+=		suse_base-6.3:../suse_base

ONLY_FOR_PLATFORM=      NetBSD-*-i386

EXTRACT_ONLY=		# empty
NO_BUILD=		yes
PLIST_SRC=		${WRKDIR}/PLIST_DYNAMIC

RPMFILES=		glib.rpm gtk.rpm

.include "../suse_linux/Makefile.common"
