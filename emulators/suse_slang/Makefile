# $NetBSD: Makefile,v 1.4 2003/06/02 01:19:52 jschauma Exp $

DISTNAME=		slang
PKGREVISION=		1
PKGNAME=		suse_slang-${SUSE_VERSION}
CATEGORIES=		emulators
MASTER_SITES=		${MASTER_SITE_SUSE:=d1/}
EXTRACT_SUFX=		.rpm

MAINTAINER=		tech-pkg@netbsd.org
HOMEPAGE=		http://www.suse.com/
COMMENT=		Linux compatibility package for slang library

DEPENDS+=		suse_base>=${SUSE_VERSION}:../suse_base

ONLY_FOR_PLATFORM=      NetBSD-*-i386 NetBSD-*-powerpc

USE_BUILDLINK2=		# defined
EXTRACT_ONLY=		# empty
NO_BUILD=		YES
PLIST_SRC=		${WRKDIR}/PLIST_DYNAMIC

RPMFILES=		${DISTNAME}${EXTRACT_SUFX}

.include "../suse_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
