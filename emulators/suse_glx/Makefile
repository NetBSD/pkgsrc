# $NetBSD: Makefile,v 1.1.1.1 2000/12/06 23:24:58 wiz Exp $
#

DISTNAME=		suse_glx-6.4
CATEGORIES=		emulators
#MASTER_SITES=		${MASTER_SITE_SUSE:=x3d2/}
MASTER_SITES=		ftp://ftp.suse.com/pub/suse/i386/6.4/suse/x3d1/
DISTFILES=		${RPMFILES}

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.suse.com/

DEPENDS+=		suse_base-6.3:../../emulators/suse_base

ONLY_FOR_PLATFORM=      NetBSD-*-i386

EXTRACT_ONLY=		# empty
NO_BUILD=		yes
PLIST_SRC=		${WRKDIR}/PLIST_DYNAMIC

RPMFILES=		glx.rpm

.include "../suse_linux/suse.mk"
