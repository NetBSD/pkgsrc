# $NetBSD: Makefile,v 1.8 2000/12/16 22:37:33 tron Exp $

DISTNAME=		xforms
PKGNAME=		suse_xforms-6.3
CATEGORIES=		emulators
MASTER_SITES=		${MASTER_SITE_SUSE:=xdev2/}
EXTRACT_SUFX=		.rpm

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.suse.com/

DEPENDS+=		suse_x11-6.3:../suse_x11

ONLY_FOR_PLATFORM=      NetBSD-*-i386

EXTRACT_ONLY=		# empty
NO_BUILD=		yes
PLIST_SRC=		${WRKDIR}/PLIST_DYNAMIC

RPMFILES=		${DISTNAME}${EXTRACT_SUFX}

.include "../suse_linux/Makefile.common"
