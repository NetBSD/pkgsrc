# $NetBSD: Makefile,v 1.3 2003/07/17 21:35:54 grant Exp $

DISTNAME=		suse_libpng-${SUSE_VERSION}
CATEGORIES=		emulators
MASTER_SITES=		${MASTER_SITE_SUSE:=gra1/}
DISTFILES=		${RPMFILES}

MAINTAINER=		hubertf@NetBSD.org
HOMEPAGE=		http://www.suse.com/
COMMENT=		Linux compatibility package for png library

DEPENDS+=		suse_base-${SUSE_VERSION}*:../suse64_base

ONLY_FOR_PLATFORM=      NetBSD-*-i386

EXTRACT_ONLY=		# empty
NO_BUILD=		yes
PLIST_SRC=		${WRKDIR}/PLIST_DYNAMIC

RPMFILES=		libpng.rpm

.include "../suse64_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
