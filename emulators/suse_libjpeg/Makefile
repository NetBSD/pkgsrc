# $NetBSD: Makefile,v 1.2 2000/12/16 22:37:32 tron Exp $

DISTNAME=		suse_libjpeg-6.4
CATEGORIES=		emulators
MASTER_SITES=		${MASTER_SITE_SUSE:C/6.3/6.4/:S,$,gra1/,}
DISTFILES=		${RPMFILES}

MAINTAINER=		hubertf@netbsd.org
HOMEPAGE=		http://www.suse.com/

DEPENDS+=		suse_base-6.3:../suse_base

ONLY_FOR_PLATFORM=      NetBSD-*-i386

EXTRACT_ONLY=		# empty
NO_BUILD=		yes
PLIST_SRC=		${WRKDIR}/PLIST_DYNAMIC

RPMFILES=		libjpeg.rpm

.include "../suse_linux/Makefile.common"
