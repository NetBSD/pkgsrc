# $NetBSD: Makefile,v 1.31 2002/04/04 10:01:31 tron Exp $

DISTNAME=		mtv-1.2.5
CATEGORIES=		graphics
MASTER_SITES=		ftp://ftp.mpegtv.com/pub/mpeg/mpegtv/player/x86-unknown-linux-glibc2.1/packages/RPMS/
DISTFILES=		${DISTNAME}-1.i386.rpm SDL-1.1.2-1.i386.rpm

MAINTAINER=		tron@netbsd.org
HOMEPAGE=		http://www.mpegtv.com/
COMMENT=		MPEG Video+Audio and VCD Player

DEPENDS+=		suse_audio>=7.3:../../emulators/suse_audio
DEPENDS+=		suse_xforms>=7.3:../../emulators/suse_xforms

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
