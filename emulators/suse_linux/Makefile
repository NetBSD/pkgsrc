# $NetBSD: Makefile,v 1.9 2000/05/31 05:02:56 dmcmahill Exp $

DISTNAME=		suse_linux-6.3
CATEGORIES=		emulators
MASTER_SITES=		# empty
DISTFILES=		# empty

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.suse.com/

DEPENDS+=		suse_libc5-6.3:../suse_libc5
DEPENDS+=		suse_xforms-6.3:../suse_xforms

ONLY_FOR_PLATFORM=      NetBSD-*-i386

EXTRACT_ONLY=		# empty
NO_BUILD=		yes
NO_CHECKSUM=		yes

do-install:		# empty

.include "../../mk/bsd.pkg.mk"
