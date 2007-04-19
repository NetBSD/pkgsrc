# $NetBSD: Makefile,v 1.4 2007/04/19 15:30:22 xtraeme Exp $

DISTNAME=		suse_slang-${SUSE_VERSION}
PKGREVISION=		2
CATEGORIES=		emulators
MASTER_SITES=		${MASTER_SITE_SUSE100}
DISTFILES=		${RPMFILES}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.suse.com/
COMMENT=		Linux compatibility package for slang library

DEPENDS+=		suse_base-${SUSE_VERSION}{,nb*}:../../emulators/suse100_base

EXTRACT_ONLY=		# empty
NO_BUILD=		YES
PLIST_SRC=		${WRKDIR}/PLIST_DYNAMIC
PLIST_SUBST+=		EMULSUBDIR=${EMULSUBDIR:Q}

SUSE_INCLUDE_MAKEFILE_ARCH=	yes

post-install:
	cd ${PREFIX}/${EMULSUBDIR}/usr/lib &&  \
		${LN} -sf libslang-utf8.so.1 libslang.so.1

.include "../../emulators/suse100_linux/Makefile.common"
.include "../../mk/bsd.pkg.mk"
