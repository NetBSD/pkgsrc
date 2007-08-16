# $NetBSD: Makefile,v 1.24 2007/08/16 08:59:43 tnn Exp $
#
# WARNING: updating this package (as of the 1.1/1.2 releases) means
# updating BUILDLINK_ABI_DEPENDS in buildlink3.mk and a PKGREVISION
# bump of all first-level dependents.  This is because the shlib
# name contains the exact libevent release number, preventing it
# from being ABI compatible across releases until this is fixed.
# [tvierling 20070210]

DISTNAME=	libevent-1.3d
CATEGORIES=	devel
MASTER_SITES=	http://monkey.org/~provos/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://monkey.org/~provos/libevent/
COMMENT=	Asynchronous event notification library

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
TEST_TARGET=	verify
PKG_DESTDIR_SUPPORT=	user-destdir

LIBS.SunOS+=	-lnsl -lresolv

# XXX helps build, but needs more testing
#CFLAGS.Interix+=	-Dsockaddr_storage=sockaddr_in -DNI_MAXSERV=32

.include "../../mk/bsd.prefs.mk"

# Solaris and HPUX don't have u_intX_t types in <inttypes.h>.
.if ${OPSYS} == "SunOS" || ${OPSYS} == "HPUX"
CFLAGS+=	-Du_int8_t=uint8_t
CFLAGS+=	-Du_int16_t=uint16_t
CFLAGS+=	-Du_int32_t=uint32_t

SUBST_CLASSES+=		inttypes
SUBST_STAGE.inttypes=	post-patch
SUBST_FILES.inttypes=	event.h
SUBST_SED.inttypes=	-e "s,u_int8_t,uint8_t,g"
SUBST_SED.inttypes+=	-e "s,u_int16_t,uint16_t,g"
SUBST_SED.inttypes+=	-e "s,u_int32_t,uint32_t,g"
.endif

.include "../../mk/bsd.pkg.mk"
