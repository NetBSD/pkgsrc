# $NetBSD: Makefile,v 1.8 2004/04/24 22:46:08 jlam Exp $

DISTNAME=		ymessenger-0.93.0
CATEGORIES=		chat
MASTER_SITES=		http://download.yahoo.com/dl/unix/linux/
DISTFILES=		${DISTNAME}-1.i386.rpm

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://messenger.yahoo.com/
COMMENT=		Yahoo! instant messaging client

DEPENDS+=		suse_compat>=6.4:../../emulators/${SUSE_DIR_PREFIX}_compat
DEPENDS+=		suse_gtk>=6.4:../../emulators/${SUSE_DIR_PREFIX}_gtk

ONLY_FOR_PLATFORM=	NetBSD-1.4[Y-Z]-i386 NetBSD-1.4Z[A-Z]-i386 \
			NetBSD-1.[5-9]*-i386 NetBSD-[2-9]*-i386

CHECK_SHLIBS=		no

DIST_SUBDIR=		.

RESTRICTED=		"Commercial software."
NO_SRC_ON_FTP=		${RESTRICTED}
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}

EXTRACT_ONLY=		# empty
NO_BUILD=		yes
PLIST_SRC=		${WRKDIR}/PLIST_DYNAMIC
PLIST_SUBST+=		EMULSUBDIR=${EMULSUBDIR}

RPMFILES=		${DISTFILES}

post-install:
	${LN} -fs ../${EMULSUBDIR}/usr/local/bin/ymessenger ${PREFIX}/bin

.include "../../emulators/suse_linux/Makefile.application"
.include "../../mk/bsd.pkg.mk"
