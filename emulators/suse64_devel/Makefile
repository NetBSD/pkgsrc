# $NetBSD: Makefile,v 1.2 2002/08/02 15:36:51 grant Exp $

DISTNAME=		suse_devel-${SUSE_VERSION}
PKGREVISION=		1
CATEGORIES=		emulators
MASTER_SITES=		${MASTER_SITE_SUSE:=d1/} \
			${MASTER_SITE_SUSE:=d2/}
DISTFILES=		${RPMFILES}

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.suse.com/
COMMENT=		Linux compatibility package - development tools

DEPENDS+=		suse_base-${SUSE_VERSION}*:../suse64_base

ONLY_FOR_PLATFORM=      NetBSD-*-i386

EXTRACT_ONLY=		# empty
NO_BUILD=		yes
PLIST_SRC=		${WRKDIR}/PLIST_DYNAMIC

RPMFILES=		bin86.rpm binutils.rpm g77.rpm gcc.rpm gpp.rpm \
			libc-2.1.3-204.i386.rpm linclude.rpm make.rpm

.include "../suse64_linux/Makefile.common"
