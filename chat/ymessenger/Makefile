# $NetBSD: Makefile,v 1.2 2001/08/20 04:10:20 jlam Exp $

DISTNAME=		ymessenger-0.93.0
CATEGORIES=		chat
MASTER_SITES=		http://download.yahoo.com/dl/unix/linux/
DISTFILES=		${DISTNAME}-1.i386.rpm

MAINTAINER=		jlam@netbsd.org
HOMEPAGE=		http://messenger.yahoo.com/
COMMENT=		Yahoo! instant messaging client

DEPENDS+=		suse_compat>=6.4:../../emulators/suse_compat
DEPENDS+=		suse_gtk>=6.4:../../emulators/suse_gtk

ONLY_FOR_PLATFORM=	NetBSD-1.4[Y-Z]-i386 NetBSD-1.4Z[A-Z]-i386 \
			NetBSD-1.5_ALPHA-i386 NetBSD-1.[5-9]*-i386

CHECK_SHLIBS=		no

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

.include "../../emulators/suse_linux/Makefile.common"
