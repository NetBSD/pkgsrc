# $NetBSD: Makefile,v 1.10 2001/01/25 09:29:10 tron Exp $

DISTNAME=		suse_devel-${SUSE_VERSION}
CATEGORIES=		emulators
MASTER_SITES=		${MASTER_SITE_SUSE:=d1/} \
			${MASTER_SITE_SUSE:=d2/}
DISTFILES=		${RPMFILES}

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.suse.com/

DEPENDS+=		suse_base>=${SUSE_VERSION}:../suse_base

ONLY_FOR_PLATFORM=      NetBSD-*-i386

EXTRACT_ONLY=		# empty
NO_BUILD=		yes
PLIST_SRC=		${WRKDIR}/PLIST_DYNAMIC

RPMFILES=		bin86.rpm binutils.rpm g77.rpm gcc.rpm gpp.rpm \
			libc.rpm linclude.rpm make.rpm

.include "../suse_linux/Makefile.common"
