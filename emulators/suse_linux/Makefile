# $NetBSD: Makefile,v 1.20 2002/11/25 11:01:16 schmonz Exp $

DISTNAME=		suse_linux-7.3
CATEGORIES=		emulators
MASTER_SITES=		# empty
DISTFILES=		# empty

MAINTAINER=		tron@netbsd.org
HOMEPAGE=		http://www.suse.com/
COMMENT=		Linux compatibility package collection

DEPENDS+=		suse_audio>=7.3:../suse_audio
DEPENDS+=		suse_libjpeg>=7.3:../suse_libjpeg
DEPENDS+=		suse_libpng>=7.3:../suse_libpng
DEPENDS+=		suse_glx>=7.3:../suse_glx
DEPENDS+=		suse_gtk>=7.3:../suse_gtk
DEPENDS+=		suse_xforms>=7.3:../suse_xforms

.include "arch.mk"
.if ${SUSE_ARCH} == i386
DEPENDS+=		suse_libc5>=7.3:../suse_libc5
.endif

ONLY_FOR_PLATFORM=      NetBSD-1.5Z[C-Z]-i386 NetBSD-1.6*-i386 NetBSD-*-powerpc

EXTRACT_ONLY=		# empty
NO_BUILD=		YES
NO_CHECKSUM=		YES

do-install:		# empty

.include "../../mk/bsd.pkg.mk"
