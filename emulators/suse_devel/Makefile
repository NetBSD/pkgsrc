# $NetBSD: Makefile,v 1.6 2000/05/31 05:02:55 dmcmahill Exp $

DISTNAME=		suse_devel-6.3
CATEGORIES=		emulators
MASTER_SITES=		${MASTER_SITE_SUSE:=d1/}
DISTFILES=		${RPMFILES}

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.suse.com/

DEPENDS+=		suse_base-6.3:../suse_base

ONLY_FOR_PLATFORM=      NetBSD-*-i386

EXTRACT_ONLY=		# empty
NO_BUILD=		yes
PLIST_SRC=		${WRKDIR}/PLIST_DYNAMIC

RPMFILES=		bin86.rpm binutils.rpm egcs.rpm g77.rpm gpp.rpm \
			libc.rpm linclude.rpm make.rpm

.include "../suse_linux/suse.mk"
