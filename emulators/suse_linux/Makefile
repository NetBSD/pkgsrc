# $NetBSD: Makefile,v 1.13 2000/12/13 20:59:44 hubertf Exp $

DISTNAME=		suse_linux-6.3nb3
CATEGORIES=		emulators
MASTER_SITES=		# empty
DISTFILES=		# empty

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.suse.com/

DEPENDS+=		suse_audio-6.3:../suse_audio
DEPENDS+=		suse_libc5-6.3:../suse_libc5
DEPENDS+=		suse_gtk-6.3:../suse_gtk
DEPENDS+=		suse_xforms-6.3:../suse_xforms
DEPENDS+=		suse_libjpeg-6.4:../suse_libjpeg
DEPENDS+=		suse_libpng-7.0:../suse_libpng

ONLY_FOR_PLATFORM=      NetBSD-*-i386

EXTRACT_ONLY=		# empty
NO_BUILD=		yes
NO_CHECKSUM=		yes

do-install:		# empty

.include "../../mk/bsd.pkg.mk"
