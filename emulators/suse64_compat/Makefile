# $NetBSD: Makefile,v 1.1.1.1 2002/04/04 10:07:58 tron Exp $

DISTNAME=		compat
PKGNAME=		suse_compat-${SUSE_VERSION}
CATEGORIES=		emulators
MASTER_SITES=		${MASTER_SITE_SUSE:=a2/}
EXTRACT_SUFX=		.rpm

MAINTAINER=		tron@netbsd.org
HOMEPAGE=		http://www.suse.com/
COMMENT=		Linux compatibility package with old shared libraries

DEPENDS+=		suse_base-${SUSE_VERSION}*:../suse64_base

ONLY_FOR_PLATFORM=      NetBSD-*-i386

EXTRACT_ONLY=		# empty
NO_BUILD=		yes
PLIST_SRC=		${WRKDIR}/PLIST_DYNAMIC

RPMFILES=		${DISTNAME}${EXTRACT_SUFX}

post-install:
	${ECHO} "${EMULSUBDIR}/usr/lib/libncurses.so.2.1" >>${PLIST_SRC}

.include "../suse64_linux/Makefile.common"
