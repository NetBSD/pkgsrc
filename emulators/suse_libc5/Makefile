# $NetBSD: Makefile,v 1.9 1999/09/19 23:58:42 tron Exp $

DISTNAME=		shlibs5
PKGNAME=		suse_libc5-6.1p1
CATEGORIES=		emulators
MASTER_SITES=		${MASTER_SITE_SUSE:=a1/}
EXTRACT_SUFX=		.rpm

MAINTAINER=		tron@netbsd.org
HOMEPAGE=		http://www.suse.com/

DEPENDS+=		suse_compat-6.1p1:../suse_compat

EXTRACT_ONLY=		# empty
NO_BUILD=		yes
PLIST_SRC=		${WRKDIR}/PLIST_DYNAMIC

RPMFILES=		${DISTNAME}${EXTRACT_SUFX}

post-install:
	${ECHO} ${EMULSUBDIR}/usr/lib/libncurses.so.2.1 >>${PLIST_SRC}

.include "../suse_linux/suse.mk"
