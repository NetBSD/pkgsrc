# $NetBSD: Makefile,v 1.1.1.1 2002/04/04 10:07:58 tron Exp $

DISTNAME=		suse_x11-${SUSE_VERSION}
PKGREVISION=		1
CATEGORIES=		emulators
MASTER_SITES=		${MASTER_SITE_SUSE:=x1/} \
			ftp://ftp.suse.com/pub/suse/i386/update/${SUSE_VERSION}/x1/
DISTFILES=		${RPMFILES}

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.suse.com/
COMMENT=		Linux compatibility package for X11 binaries

DEPENDS+=		suse_base-${SUSE_VERSION}*:../suse64_base

ONLY_FOR_PLATFORM=      NetBSD-*-i386

EXTRACT_ONLY=		# empty
NO_BUILD=		yes
PLIST_SRC=		${WRKDIR}/PLIST_DYNAMIC

RPMFILES=		xshared-3.3.6-43.i386.rpm xpm.rpm

.include "../suse64_linux/Makefile.common"
