# $NetBSD: Makefile,v 1.4 1999/10/07 17:41:51 tron Exp $

DISTNAME=		suse_devel-6.1p1
CATEGORIES=		emulators
MASTER_SITES=		${MASTER_SITE_SUSE:=d1/}
DISTFILES=		${RPMFILES}

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.suse.com/

DEPENDS+=		suse_base-6.1p1:../suse_base

EXTRACT_ONLY=		# empty
NO_BUILD=		yes
PLIST_SRC=		${WRKDIR}/PLIST_DYNAMIC

RPMFILES=		bin86.rpm binutils.rpm egcs.rpm g77.rpm gpp.rpm \
			libc.rpm linclude.rpm make.rpm

.include "../suse_linux/suse.mk"
