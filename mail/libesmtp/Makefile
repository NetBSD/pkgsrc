# $NetBSD: Makefile,v 1.2 2002/10/02 22:08:43 dillo Exp $

DISTNAME=	libesmtp-1.0rc1
CATEGORIES=	mail devel
MASTER_SITES=	http://www.stafford.uklinux.net/libesmtp/ \
		http://www.tobez.org/download/port-mirrors/mail/libesmtp/ \
		http://www.borgsdemons.com/distfiles/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	dolemite@wuli.nu
HOMEPAGE=	http://www.stafford.uklinux.net/libesmtp/
COMMENT=	Library to manage posting of electronic mail

USE_BUILDLINK2=	yes
USE_GMAKE=      yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--enable-all

.include "../../devel/pth/buildlink2.mk"
.include "../../security/openssl/buildlink2.mk"
.include "../../devel/libtool/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
