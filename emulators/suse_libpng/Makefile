# $NetBSD: Makefile,v 1.1.1.1 2000/12/13 20:06:01 jdolecek Exp $

DISTNAME=		suse_libpng-7.0
CATEGORIES=		emulators
MASTER_SITES=		${MASTER_SITE_SUSE:C/6.3/7.0/:S,$,gra1/,}
DISTFILES=		${RPMFILES}

MAINTAINER=		hubertf@netbsd.org
HOMEPAGE=		http://www.suse.com/

DEPENDS+=		suse_base-6.3:../suse_base

ONLY_FOR_PLATFORM=      NetBSD-*-i386

EXTRACT_ONLY=		# empty
NO_BUILD=		yes
PLIST_SRC=		${WRKDIR}/PLIST_DYNAMIC

RPMFILES=		libpng.rpm

.include "../suse_linux/suse.mk"
