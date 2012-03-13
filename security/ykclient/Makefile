# $NetBSD: Makefile,v 1.1.1.1 2012/03/13 15:16:00 pettai Exp $

DISTNAME=	ykclient-2.7
CATEGORIES=	security
MASTER_SITES=	http://yubico-c-client.googlecode.com/files/

MAINTAINER=	pettai@NetBSD.org
HOMEPAGE=	http://code.google.com/p/yubico-c/
COMMENT=	Libraries for online validation of Yubikey OTPs

LICENSE=	modified-bsd

PKG_DESTDIR_SUPPORT=	user-destdir
GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes

.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
