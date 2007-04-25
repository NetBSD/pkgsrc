# $NetBSD: Makefile,v 1.22 2007/04/25 16:38:37 tnn Exp $
#
# WARNING: updating this package (as of the 1.1/1.2 releases) means
# updating BUILDLINK_ABI_DEPENDS in buildlink3.mk and a PKGREVISION
# bump of all first-level dependents.  This is because the shlib
# name contains the exact libevent release number, preventing it
# from being ABI compatible across releases until this is fixed.
# [tvierling 20070210]

DISTNAME=	libevent-1.3b
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

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "SunOS"
SUBST_CLASSES+=		inttypes
SUBST_STAGE.inttypes=	post-patch
SUBST_FILES.inttypes=	event.h
SUBST_SED.inttypes=	-e "s,u_int8_t,uint8_t,g"
SUBST_SED.inttypes+=	-e "s,u_int16_t,uint16_t,g"
SUBST_SED.inttypes+=	-e "s,u_int32_t,uint32_t,g"
.endif

.include "../../mk/bsd.pkg.mk"
