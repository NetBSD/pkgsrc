# $NetBSD: Makefile,v 1.20 2007/02/27 10:38:45 grant Exp $
#
# WARNING: updating this package (as of the 1.1/1.2 releases) means
# updating BUILDLINK_ABI_DEPENDS in buildlink3.mk and a PKGREVISION
# bump of all first-level dependents.  This is because the shlib
# name contains the exact libevent release number, preventing it
# from being ABI compatible across releases until this is fixed.
# [tvierling 20070210]

DISTNAME=	libevent-1.2a
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://monkey.org/~provos/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://monkey.org/~provos/libevent/
COMMENT=	Asynchronous event notification library

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
TEST_TARGET=	verify

LIBS.SunOS+=	-lnsl -lresolv

# Solaris doesn't have u_intX_t types in <inttypes.h>.
CFLAGS.SunOS+=	-Du_int8_t=uint8_t
CFLAGS.SunOS+=	-Du_int16_t=uint16_t
CFLAGS.SunOS+=	-Du_int32_t=uint32_t

# The SunPro compiler doesn't understand __inline.
.include "../../mk/compiler.mk"

.if !empty(PKGSRC_COMPILER:Msunpro)
CFLAGS.SunOS+=	-D__inline=inline
.endif

.include "../../mk/bsd.pkg.mk"
