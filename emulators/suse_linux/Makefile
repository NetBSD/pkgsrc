# $NetBSD: Makefile,v 1.19 2002/04/04 09:47:07 tron Exp $

DISTNAME=		suse_linux-7.3
CATEGORIES=		emulators
MASTER_SITES=		# empty
DISTFILES=		# empty

MAINTAINER=		tron@netbsd.org
HOMEPAGE=		http://www.suse.com/
COMMENT=		Linux compatibility package collection

DEPENDS+=		suse_audio>=7.3:../suse_audio
DEPENDS+=		suse_libc5>=7.3:../suse_libc5
DEPENDS+=		suse_libjpeg>=7.3:../suse_libjpeg
DEPENDS+=		suse_libpng>=7.3:../suse_libpng
DEPENDS+=		suse_glx>=7.3:../suse_glx
DEPENDS+=		suse_gtk>=7.3:../suse_gtk
DEPENDS+=		suse_xforms>=7.3:../suse_xforms

ONLY_FOR_PLATFORM=      NetBSD-1.5Z[C-Z]-i386 NetBSD-1.6*-i386

EXTRACT_ONLY=		# empty
NO_BUILD=		YES
NO_CHECKSUM=		YES

do-install:		# empty

.include "../../mk/bsd.pkg.mk"
