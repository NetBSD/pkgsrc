# $NetBSD: Makefile,v 1.11 1999/10/07 17:41:52 tron Exp $

DISTNAME=		shlibs5
PKGNAME=		suse_libc5-6.1p1
CATEGORIES=		emulators
MASTER_SITES=		${MASTER_SITE_SUSE:=a1/}
EXTRACT_SUFX=		.rpm

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.suse.com/

DEPENDS+=		suse_compat-6.1p1:../suse_compat

EXTRACT_ONLY=		# empty
NO_BUILD=		yes
PLIST_SRC=		${WRKDIR}/PLIST_DYNAMIC

RPMFILES=		${DISTNAME}${EXTRACT_SUFX}

.include "../suse_linux/suse.mk"
