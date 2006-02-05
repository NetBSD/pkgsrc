# $NetBSD: Makefile,v 1.7 2006/02/05 23:09:03 joerg Exp $

DISTNAME=		suse_slang-${SUSE_VERSION}
PKGREVISION=		1
CATEGORIES=		emulators
MASTER_SITES=		${MASTER_SITE_SUSE91}
DISTFILES=		${RPMFILES}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.suse.com/
COMMENT=		Linux compatibility package for slang library

DEPENDS+=		suse_base>=${SUSE_VERSION}:../../emulators/suse_base

EXTRACT_ONLY=		# empty
NO_BUILD=		YES
PLIST_SRC=		${WRKDIR}/PLIST_DYNAMIC

.if exists(Makefile.${MACHINE_ARCH})
.include "Makefile.${MACHINE_ARCH}"
.endif

post-install:
	${LN} -sf ${PREFIX}/${EMULSUBDIR}/usr/lib/libslang-utf8.so.1 \
		${PREFIX}/${EMULSUBDIR}/usr/lib/libslang.so.1

.include "../../emulators/suse91_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
