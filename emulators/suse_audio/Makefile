# $NetBSD: Makefile,v 1.13 2005/01/23 12:06:07 tron Exp $

DISTNAME=		audiofile
PKGNAME=		suse_audio-${SUSE_VERSION}
CATEGORIES=		emulators
MASTER_SITES=		${MASTER_SITE_SUSE:=snd1/}
EXTRACT_SUFX=		.rpm

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.suse.com/
COMMENT=		Linux compatibility package for audio libraries

DEPENDS+=		suse_base>=${SUSE_VERSION}:../../emulators/suse_base

ONLY_FOR_PLATFORM=      NetBSD-*-i386 NetBSD-*-powerpc FreeBSD-*-i386

EXTRACT_ONLY=		# empty
NO_BUILD=		YES
NO_BUILDLINK=		YES
PLIST_SRC=		${WRKDIR}/PLIST_DYNAMIC

RPMFILES=		${DISTNAME}${EXTRACT_SUFX}

.include "../../emulators/suse_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
