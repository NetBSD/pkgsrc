# $NetBSD: Makefile,v 1.34 2016/03/05 11:27:50 jperkin Exp $

DISTNAME=	libesmtp-1.0.6
PKGREVISION=	3
CATEGORIES=	mail devel
MASTER_SITES=	http://www.stafford.uklinux.net/libesmtp/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	dolemite@wuli.nu
HOMEPAGE=	http://www.stafford.uklinux.net/libesmtp/
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

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
