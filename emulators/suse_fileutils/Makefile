# $NetBSD: Makefile,v 1.1.1.1 2004/10/02 14:25:39 dmcmahill Exp $

DISTNAME=		suse_fileutils-${SUSE_VERSION}
CATEGORIES=		emulators
MASTER_SITES=		${MASTER_SITE_SUSE:=a1/}

DISTFILES=		${RPMFILES}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.suse.com/
COMMENT=		Linux compatibility package - fileutils

DEPENDS+=		suse_base>=${SUSE_VERSION}:../suse_base

ONLY_FOR_PLATFORM=      NetBSD-*-i386 NetBSD-*-powerpc

EXTRACT_ONLY=		# empty
NO_BUILD=		YES
PLIST_SRC=		${WRKDIR}/PLIST_DYNAMIC

RPMFILES=		fileutils.rpm

.include "../suse_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
