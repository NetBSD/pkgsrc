# $NetBSD: Makefile,v 1.1.1.1 2002/04/04 10:07:58 tron Exp $

DISTNAME=		suse_linux-6.4
CATEGORIES=		emulators
MASTER_SITES=		# empty
DISTFILES=		# empty

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.suse.com/
COMMENT=		Linux compatibility package collection

DEPENDS+=		suse_audio-6.4*:../suse64_audio
DEPENDS+=		suse_libc5-6.4*:../suse64_libc5
DEPENDS+=		suse_libjpeg-6.4*:../suse64_libjpeg
DEPENDS+=		suse_libpng-6.4*:../suse64_libpng
DEPENDS+=		suse_glx-6.4*:../suse64_glx
DEPENDS+=		suse_gtk-6.4*:../suse64_gtk
DEPENDS+=		suse_xforms-6.4*:../suse64_xforms

ONLY_FOR_PLATFORM=      NetBSD-*-i386

EXTRACT_ONLY=		# empty
NO_BUILD=		yes
NO_CHECKSUM=		yes

do-install:		# empty

.include "../../mk/bsd.pkg.mk"
