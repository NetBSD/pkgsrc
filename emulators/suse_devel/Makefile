# $NetBSD: Makefile,v 1.2 1999/09/19 23:58:41 tron Exp $

DISTNAME=		suse_devel-6.1p1
CATEGORIES=		emulators
MASTER_SITES=		${MASTER_SITE_SUSE:=x1/}
DISTFILES=		${RPMFILES}

MAINTAINER=		tron@netbsd.org
HOMEPAGE=		http://www.suse.com/

DEPENDS+=		suse_base-6.1p1:../suse_base

EXTRACT_ONLY=		# empty
NO_BUILD=		yes
PLIST_SRC=		${WRKDIR}/PLIST_DYNAMIC

RPMFILES=		bin86.rpm binutils.rpm egcs.rpm g77.rpm gpp.rpm \
			libc.rpm linclude.rpm make.rpm

.include "../suse_linux/suse.mk"
