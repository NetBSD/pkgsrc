# $NetBSD: Makefile,v 1.15 2000/04/26 14:13:30 tron Exp $

DISTNAME=		mtv-1.1.1.0
CATEGORIES=		graphics
MASTER_SITES=		ftp://ftp.mpegtv.com/pub/mpeg/mpegtv/player/x86-unknown-linux-glibc2.1/packages/RPMS/
DISTFILES=		${DISTNAME}-1.i386.rpm SDL-1.1.2-1.i386.rpm
ONLY_FOR_PLATFORM=	NetBSD-1.4[X-Z]-i386 NetBSD-1.[5-9]*-i386

MAINTAINER=		tron@netbsd.org
HOMEPAGE=		http://www.mpegtv.com/

DEPENDS=		suse_xforms>=6.3:../../emulators/suse_xforms

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
