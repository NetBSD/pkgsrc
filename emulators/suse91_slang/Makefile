# $NetBSD: Makefile,v 1.1.1.1 2005/04/02 19:44:24 jdolecek Exp $

DISTNAME=		suse_slang-${SUSE_VERSION}
CATEGORIES=		emulators
MASTER_SITES=		${MASTER_SITE_SUSE91}
DISTFILES=		${RPMFILES}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.suse.com/
COMMENT=		Linux compatibility package for slang library

DEPENDS+=		suse_base>=${SUSE_VERSION}:../suse_base

ONLY_FOR_PLATFORM=      NetBSD-*-i386 NetBSD-*-powerpc FreeBSD-*-i386

EXTRACT_ONLY=		# empty
NO_BUILD=		YES
NO_BUILDLINK=		YES
PLIST_SRC=		${WRKDIR}/PLIST_DYNAMIC

RPMFILES=		slang-1.4.9-121.${SUSE_ARCH}.rpm

post-install:
	${LN} -sf ${PREFIX}/${EMULSUBDIR}/usr/lib/libslang-utf8.so.1 \
		${PREFIX}/${EMULSUBDIR}/usr/lib/libslang.so.1

.include "../suse91_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
