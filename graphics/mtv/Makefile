# $NetBSD: Makefile,v 1.20 2000/07/01 19:42:25 david Exp $

DISTNAME=		mtv-1.1.1.1
CATEGORIES=		graphics
MASTER_SITES=		ftp://ftp.mpegtv.com/pub/mpeg/mpegtv/player/x86-unknown-linux-glibc2.1/packages/RPMS/
DISTFILES=		${DISTNAME}-1.i386.rpm SDL-1.1.2-1.i386.rpm

MAINTAINER=		tron@netbsd.org
HOMEPAGE=		http://www.mpegtv.com/

DEPENDS=		suse_xforms>=6.3:../../emulators/suse_xforms

ONLY_FOR_PLATFORM=	NetBSD-1.4[Y-Z]-i386 NetBSD-1.4Z[A-Z]-i386 \
			NetBSD-1.5_ALPHA-i386 NetBSD-1.[5-9]*-i386

DIST_SUBDIR=		mtv
LICENSE=		fee-based-commercial-use
MANCOMPRESSED=
MIRROR_DISTFILE=	no

EXTRACT_ONLY=		# empty
NO_BUILD=		yes
PLIST_SRC=		${WRKDIR}/PLIST_DYNAMIC

RPMFILES=		${DISTFILES}

post-install:
.for FILE in mtv mtvp
	${LN} -fs ../${EMULSUBDIR}/usr/X11R6/bin/${FILE} ${PREFIX}/bin
.endfor
	${CHMOD} +x ${PREFIX}/emul/linux/usr/doc/mtv

.include "../../emulators/suse_linux/suse.mk"
