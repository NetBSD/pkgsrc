# $NetBSD: Makefile,v 1.39 2020/01/18 21:48:15 jperkin Exp $

DISTNAME=	libesmtp-1.0.6
PKGREVISION=	5
CATEGORIES=	mail devel
#MASTER_SITES=	http://www.stafford.uklinux.net/libesmtp/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	dolemite@wuli.nu
#HOMEPAGE=	http://www.stafford.uklinux.net/libesmtp/
COMMENT=	Library to manage posting of electronic mail
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2.1

USE_TOOLS+=	gmake
USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes

CONFIGURE_ARGS+=	--enable-all
CONFIGURE_ARGS+=	--disable-ntlm
CONFIGURE_ARGS+=	--disable-isoc

CPPFLAGS+=	-DHAVE_SNPRINTF=1 -DHAVE_VSNPRINTF=1

.include "../../mk/bsd.prefs.mk"

.if !empty(MACHINE_PLATFORM:MIRIX-5.*)
CONFIGURE_ARGS+=	--enable-emulate-getaddrinfo
.endif

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
