# $NetBSD: Makefile,v 1.1.1.1 2002/04/04 10:07:58 tron Exp $

DISTNAME=		suse_libpng-${SUSE_VERSION}
CATEGORIES=		emulators
MASTER_SITES=		${MASTER_SITE_SUSE:=gra1/}
DISTFILES=		${RPMFILES}

MAINTAINER=		hubertf@netbsd.org
HOMEPAGE=		http://www.suse.com/
COMMENT=		Linux compatibility package for png library

DEPENDS+=		suse_base-${SUSE_VERSION}*:../suse64_base

ONLY_FOR_PLATFORM=      NetBSD-*-i386

EXTRACT_ONLY=		# empty
NO_BUILD=		yes
PLIST_SRC=		${WRKDIR}/PLIST_DYNAMIC

RPMFILES=		libpng.rpm

.include "../suse64_linux/Makefile.common"
