# $NetBSD: Makefile,v 1.15 2000/12/17 13:06:24 tron Exp $

DISTNAME=		suse_linux-6.4
CATEGORIES=		emulators
MASTER_SITES=		# empty
DISTFILES=		# empty

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.suse.com/

DEPENDS+=		suse_audio-6.4:../suse_audio
DEPENDS+=		suse_libc5-6.4:../suse_libc5
DEPENDS+=		suse_libjpeg-6.4:../suse_libjpeg
DEPENDS+=		suse_libpng-6.4:../suse_libpng
DEPENDS+=		suse_glx-6.4:../suse_gtk
DEPENDS+=		suse_gtk-6.4:../suse_gtk
DEPENDS+=		suse_xforms-6.4:../suse_xforms

ONLY_FOR_PLATFORM=      NetBSD-*-i386

EXTRACT_ONLY=		# empty
NO_BUILD=		yes
NO_CHECKSUM=		yes

do-install:		# empty

.include "../../mk/bsd.pkg.mk"
