# $NetBSD: Makefile,v 1.10 2005/12/12 14:43:23 joerg Exp $

DISTNAME=		ymessenger-0.93.0
CATEGORIES=		chat
MASTER_SITES=		http://download.yahoo.com/dl/unix/linux/
DISTFILES=		${DISTNAME}-1.i386.rpm

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://messenger.yahoo.com/
COMMENT=		Yahoo! instant messaging client

RPMFILES=		${DISTFILES}

.include "../../emulators/suse_linux/Makefile.application"

.if !defined(USE_NATIVE_LINUX)
DEPENDS+=		suse_compat>=6.4:../../emulators/${SUSE_DIR_PREFIX}_compat
DEPENDS+=		suse_gtk>=6.4:../../emulators/${SUSE_DIR_PREFIX}_gtk
.endif

ONLY_FOR_PLATFORM=	*-*-i386

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
PLIST_SUBST+=		EMULSUBDIR=${EMULSUBDIR:Q}

post-install:
	${LN} -fs ../${EMULSUBDIR}/usr/local/bin/ymessenger ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
