# $NetBSD: Makefile,v 1.5 2004/01/11 19:41:39 cjep Exp $

DISTNAME=		freetype2
PKGNAME=		suse_${DISTNAME}-${SUSE_VERSION}
CATEGORIES=		emulators
PKGREVISION=		1
MASTER_SITES=		${MASTER_SITE_SUSE:=gra1/} \
			${MASTER_SITE_SUSE_UPD:=gra1/}
DISTFILES=		${RPMFILES}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.suse.com/
COMMENT=		Linux compatibility package for the FreeType2 library

DEPENDS+=		suse_base>=${SUSE_VERSION}:../suse_base

ONLY_FOR_PLATFORM=      NetBSD-*-i386 NetBSD-*-powerpc

USE_BUILDLINK2=		YES
NO_BUILD=		YES
EXTRACT_ONLY=		# empty
PLIST_SRC=		${WRKDIR}/PLIST_DYNAMIC

RPMFILES+=      	freetype2-2.0.4-52.${SUSE_ARCH}.rpm

.include "../suse_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
