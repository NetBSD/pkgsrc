# $NetBSD: Makefile,v 1.22 2006/02/05 23:09:55 joerg Exp $

DISTNAME=	libesmtp-1.0.3r1
PKGNAME=	${DISTNAME:S/r1//}
PKGREVISION=	2
CATEGORIES=	mail devel
MASTER_SITES=	http://www.stafford.uklinux.net/libesmtp/ \
		http://www.tobez.org/download/port-mirrors/mail/libesmtp/ \
		http://www.borgsdemons.com/distfiles/
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

.if !empty(LOWER_OPSYS:Mirix5*)
CONFIGURE_ARGS+=	--enable-emulate-getaddrinfo
.endif

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
