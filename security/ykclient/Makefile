# $NetBSD: Makefile,v 1.4 2012/11/10 19:17:26 pettai Exp $

DISTNAME=	ykclient-2.9
CATEGORIES=	security
MASTER_SITES=	http://yubico-c-client.googlecode.com/files/

MAINTAINER=	pettai@NetBSD.org
HOMEPAGE=	http://code.google.com/p/yubico-c-client/
COMMENT=	Libraries for online validation of Yubikey OTPs

LICENSE=	modified-bsd

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes

.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
