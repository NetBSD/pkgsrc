# $NetBSD: Makefile,v 1.10 2000/08/09 13:09:50 abs Exp $

DISTNAME=		suse_linux-6.3nb1
CATEGORIES=		emulators
MASTER_SITES=		# empty
DISTFILES=		# empty

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.suse.com/

DEPENDS+=		suse_libc5-6.3:../suse_libc5
DEPENDS+=		suse_gtk-6.3:../suse_gtk
DEPENDS+=		suse_xforms-6.3:../suse_xforms

ONLY_FOR_PLATFORM=      NetBSD-*-i386

EXTRACT_ONLY=		# empty
NO_BUILD=		yes
NO_CHECKSUM=		yes

do-install:		# empty

.include "../../mk/bsd.pkg.mk"
