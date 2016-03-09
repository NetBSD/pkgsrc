# $NetBSD: Makefile,v 1.18 2016/03/09 18:04:17 gdt Exp $

VERSION=	4.1.1
DISTNAME=	libotr-${VERSION}
PKGNAME=	libotr-${VERSION}
CATEGORIES=	chat security
MASTER_SITES=	http://www.cypherpunks.ca/otr/

MAINTAINER=	nathanw@NetBSD.org
# also gdt@NetBSD.org
HOMEPAGE=	http://www.cypherpunks.ca/otr/
COMMENT=	Library for Off-The-Record encrypted messaging
LICENSE=	gnu-gpl-v2

# Work around rc tarballs that unpack to bare version.
WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--with-pic

USE_LIBTOOL=	yes

# There's an apparent bug in gcc 4.1.3 on i386 (as shipped in
# netbsd-5).  With -O2 and the stack protector (SSP) feature, the
# function otrl_auth_handle_revealsig is badly miscompiled.

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
