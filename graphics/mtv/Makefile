# $NetBSD: Makefile,v 1.10 1999/10/07 17:41:54 tron Exp $

DISTNAME=		mtv-1.1.0.3
CATEGORIES=		graphics
MASTER_SITES=		ftp://ftp.mpegtv.com/pub/mpeg/mpegtv/player/x86-unknown-linux-glibc/packages/RPMS/ \
			ftp://ftp.mpeg.org/pub/mpeg/mpegtv/player/x86-unknown-linux-glibc/packages/RPMS/
DISTFILES=		${DISTNAME}-1.i386.rpm SDL-0.9.9-5.i386.rpm
ONLY_FOR_PLATFORM=	NetBSD-1.4[K-Z]-i386 NetBSD-1.[5-9]*-i386

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.mpegtv.com/

DEPENDS=		suse_xforms-6.1p1:../../emulators/suse_xforms

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

.include "../../emulators/suse_linux/suse.mk"
