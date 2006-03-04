# $NetBSD: Makefile,v 1.8 2006/03/04 21:29:36 jlam Exp $

DISTNAME=		suse_slang-${SUSE_VERSION}
PKGREVISION=		1
CATEGORIES=		emulators
MASTER_SITES=		${MASTER_SITE_SUSE91}
DISTFILES=		${RPMFILES}

MAINTAINER=		pkgsrc-users@NetBSD.org
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
