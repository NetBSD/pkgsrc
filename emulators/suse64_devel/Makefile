# $NetBSD: Makefile,v 1.5 2003/07/17 21:35:50 grant Exp $

DISTNAME=		suse_devel-${SUSE_VERSION}
PKGREVISION=		2
CATEGORIES=		emulators
MASTER_SITES=		${MASTER_SITE_SUSE:=d1/} \
			${MASTER_SITE_SUSE:=d2/}
DISTFILES=		${RPMFILES}

MAINTAINER=		tech-pkg@NetBSD.org
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
.include "../../mk/bsd.pkg.mk"
