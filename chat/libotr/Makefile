# $NetBSD: Makefile,v 1.13 2012/09/06 00:23:18 gdt Exp $

VERSION=	4.0.0
DISTNAME=	libotr-${VERSION}
CATEGORIES=	chat security
MASTER_SITES=	http://www.cypherpunks.ca/otr/

MAINTAINER=	nathanw@NetBSD.org
# also gdt@NetBSD.org
HOMEPAGE=	http://www.cypherpunks.ca/otr/
COMMENT=	Library for Off-The-Record encrypted messaging
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--with-pic

USE_LIBTOOL=	yes

# There's an apparent bug in gcc 4.1.3 on i386 (as shipped in
# netbsd-5).  With -O2 and the stack protector (SSP) feature, the
# function otrl_auth_handle_revealsig is badly miscompiled.
# Therefore, we turn down optimization, since that seems better than
# turning off the stack protector.

#Not apparently relevant, but makes -S output easier to follow.
#CFLAGS+=		-ggdb
#A way to avoid the bug.
#CFLAGS+=		-O1

# Avoid optimization/SSP bug.
CONFIGURE_ARGS+=	--disable-gcc-hardening

# This seems irrelevant, but was on the list to check, and thus is
# left as a hint to others.
#CONFIGURE_ARGS+=	--disable-linker-hardening

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../security/libgcrypt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
