# $NetBSD: Makefile,v 1.13 2004/04/14 11:31:12 xtraeme Exp $

DISTNAME=		libjpeg
PKGNAME=		suse_${DISTNAME}-${SUSE_VERSION}
CATEGORIES=		emulators
MASTER_SITES=		${MASTER_SITE_SUSE:=gra1/}
EXTRACT_SUFX=		.rpm

MAINTAINER=		tron@NetBSD.org
HOMEPAGE=		http://www.suse.com/
COMMENT=		Linux compatibility package for the JPEG library

DEPENDS+=		suse_base>=${SUSE_VERSION}:../../emulators/suse_base

ONLY_FOR_PLATFORM=      NetBSD-*-i386 NetBSD-*-powerpc FreeBSD-*-i386

USE_BUILDLINK2=		# defined
EXTRACT_ONLY=		# empty
NO_BUILD=		YES
PLIST_SRC=		${WRKDIR}/PLIST_DYNAMIC

RPMFILES=		${DISTNAME}${EXTRACT_SUFX}

.include "../../emulators/suse_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
