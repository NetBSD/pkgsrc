# $NetBSD: Makefile,v 1.13 2002/04/04 09:46:57 tron Exp $

DISTNAME=		suse_devel-${SUSE_VERSION}
CATEGORIES=		emulators
MASTER_SITES=		${MASTER_SITE_SUSE:=d1/} \
			${MASTER_SITE_SUSE:=d2/} \
			${MASTER_SITE_SUSE_UPD:=d1/}

DISTFILES=		${RPMFILES}

MAINTAINER=		tron@netbsd.org
HOMEPAGE=		http://www.suse.com/
COMMENT=		Linux compatibility package - development tools

DEPENDS+=		suse_base>=${SUSE_VERSION}:../suse_base

ONLY_FOR_PLATFORM=      NetBSD-*-i386

EXTRACT_ONLY=		# empty
NO_BUILD=		YES
PLIST_SRC=		${WRKDIR}/PLIST_DYNAMIC

RPMFILES=		bin86.rpm binutils.rpm cpp.rpm g77.rpm gcc.rpm \
			glibc-devel-2.2.4-64.i386.rpm gpp.rpm make.rpm

.include "../suse_linux/Makefile.common"
