# $NetBSD: Makefile,v 1.4 1999/05/24 21:27:14 tron Exp $

DISTNAME=		suse_linux-6.1
CATEGORIES=		emulators
MASTER_SITES=		# empty
DISTFILES=		# empty
ONLY_FOR_PLATFORM=	NetBSD-*-i386

MAINTAINER=		tron@netbsd.org
HOMEPAGE=		http://www.suse.com/

DEPENDS=		suse_compat-6.1:../suse_compat \
			suse_libc5-6.1:../suse_libc5 \
			suse_xforms-6.1:../suse_xforms

EXTRACT_ONLY=		# empty
NO_BUILD=		yes
NO_CHECKSUM=		yes

do-install:		# empty

.include "../../mk/bsd.pkg.mk"
