# $NetBSD: Makefile,v 1.1.1.1 1999/05/17 22:12:03 tron Exp $

DISTNAME=	suse_linux-6.1
CATEGORIES=	emulators
MASTER_SITES=	# empty
DISTFILES=	# empty
ONLY_FOR_ARCHS=	i386

MAINTAINER=	tron@netbsd.org
HOMEPAGE=	http://www.suse.com/

DEPENDS+=	suse_libc5-6.1:../suse_libc5
DEPENDS+=	suse_xforms-6.1:../suse_xforms

EXTRACT_ONLY=	# empty
NO_BUILD=	yes
NO_CHECKSUM=	yes
NO_CONFIGURE=	yes
NO_PATCH=	yes

do-install:	# empty

.include "../../mk/bsd.pkg.mk"
