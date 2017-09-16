# $NetBSD: Makefile,v 1.36 2017/09/16 12:47:45 tnn Exp $

DISTNAME=	libesmtp-1.0.6
PKGREVISION=	3
CATEGORIES=	mail devel
#MASTER_SITES=	http://www.stafford.uklinux.net/libesmtp/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	dolemite@wuli.nu
#HOMEPAGE=	http://www.stafford.uklinux.net/libesmtp/
COMMENT=	Library to manage posting of electronic mail

USE_TOOLS+=	gmake
USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes

USE_OLD_DES_API=	yes
CONFIGURE_ARGS+=	--enable-all
CONFIGURE_ARGS+=	--disable-isoc

.include "../../mk/bsd.prefs.mk"

.if !empty(MACHINE_PLATFORM:MIRIX-5*)
CONFIGURE_ARGS+=	--enable-emulate-getaddrinfo
.endif

.if !empty(MACHINE_PLATFORM:M*)
# assume all platforms have working snprintf these days.
CPPFLAGS+=	-DHAVE_SNPRINTF=1 -DHAVE_VSNPRINTF=1
.endif

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
