# $NetBSD: Makefile,v 1.1.1.1 2002/04/04 10:07:58 tron Exp $

DISTNAME=		suse_libjpeg-${SUSE_VERSION}
PKGREVISION=		1
CATEGORIES=		emulators
MASTER_SITES=		${MASTER_SITE_SUSE:=gra1/} \
			ftp://ftp.suse.com/pub/suse/i386/update/${SUSE_VERSION}/gra1/
DISTFILES=		${RPMFILES}

MAINTAINER=		hubertf@netbsd.org
HOMEPAGE=		http://www.suse.com/
COMMENT=		Linux compatibility package for jpeg binary

DEPENDS+=		suse_base-${SUSE_VERSION}*:../suse64_base

ONLY_FOR_PLATFORM=      NetBSD-*-i386

EXTRACT_ONLY=		# empty
NO_BUILD=		yes
PLIST_SRC=		${WRKDIR}/PLIST_DYNAMIC

RPMFILES=		libjpeg-6.2.0-62.i386.rpm

.include "../suse64_linux/Makefile.common"
