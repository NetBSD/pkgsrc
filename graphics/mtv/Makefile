# $NetBSD: Makefile,v 1.30 2002/04/03 11:00:01 tron Exp $

DISTNAME=		mtv-1.2.5
CATEGORIES=		graphics
MASTER_SITES=		ftp://ftp.mpegtv.com/pub/mpeg/mpegtv/player/x86-unknown-linux-glibc2.1/packages/RPMS/
DISTFILES=		${DISTNAME}-1.i386.rpm SDL-1.1.2-1.i386.rpm

MAINTAINER=		tron@netbsd.org
HOMEPAGE=		http://www.mpegtv.com/
COMMENT=		MPEG Video+Audio and VCD Player

DEPENDS+=		suse_audio>=6.3:../../emulators/suse_audio
DEPENDS+=		suse_xforms>=6.3:../../emulators/suse_xforms

ONLY_FOR_PLATFORM=	NetBSD-1.4[Y-Z]-i386 NetBSD-1.4Z[A-Z]-i386 \
			NetBSD-1.5_ALPHA-i386 NetBSD-1.[5-9]*-i386

DIST_SUBDIR=		mtv
LICENSE=		fee-based-commercial-use
MANCOMPRESSED=
CHECK_SHLIBS=		no

RESTRICTED=		"Commercial software."
NO_SRC_ON_FTP=		${RESTRICTED}
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}

EXTRACT_ONLY=		# empty
NO_BUILD=		yes
PLIST_SRC=		${WRKDIR}/PLIST_DYNAMIC

RPMFILES=		${DISTFILES}

post-install:
.for FILE in mtv mtvp
	${LN} -fs ../${EMULSUBDIR}/usr/X11R6/bin/${FILE} ${PREFIX}/bin
.endfor
	${CHMOD} +x ${PREFIX}/emul/linux/usr/doc/mtv

.include "../../emulators/suse_linux/Makefile.common"
