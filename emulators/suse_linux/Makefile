# $NetBSD: Makefile,v 1.27 2005/01/23 12:06:08 tron Exp $

DISTNAME=		suse_linux-7.3
CATEGORIES=		emulators
MASTER_SITES=		# empty
DISTFILES=		# empty

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.suse.com/
COMMENT=		Linux compatibility package collection

DEPENDS+=		suse_audio>=7.3:../suse_audio
DEPENDS+=		suse_libjpeg>=7.3:../suse_libjpeg
DEPENDS+=		suse_libpng>=7.3:../suse_libpng
DEPENDS+=		suse_libtiff>=7.3:../suse_libtiff
DEPENDS+=		suse_glx>=7.3:../suse_glx
DEPENDS+=		suse_gtk>=7.3:../suse_gtk
DEPENDS+=		suse_xforms>=7.3:../suse_xforms

.include "../../emulators/suse_linux/arch.mk"
.if ${SUSE_ARCH} == i386
DEPENDS+=		suse_libc5>=7.3:../suse_libc5
.endif

ONLY_FOR_PLATFORM=	NetBSD-1.5Z[C-Z]-i386 NetBSD-1.6*-i386 \
			NetBSD-[2-9]*-i386 NetBSD-*-powerpc \
			FreeBSD-*-i386

EXTRACT_ONLY=		# empty
NO_BUILD=		YES
NO_BUILDLINK=		YES
NO_CHECKSUM=		YES

do-install:		# empty

.include "../../mk/bsd.pkg.mk"
