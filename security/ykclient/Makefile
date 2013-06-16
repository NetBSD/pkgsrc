# $NetBSD: Makefile,v 1.7 2013/06/16 09:35:54 pettai Exp $

DISTNAME=	ykclient-2.10
CATEGORIES=	security
MASTER_SITES=	http://yubico.github.io/yubico-c-client/releases/

MAINTAINER=	pettai@NetBSD.org
HOMEPAGE=	http://yubico.github.io/yubico-c-client/
COMMENT=	Libraries for online validation of Yubikey OTPs

LICENSE=	modified-bsd

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes

.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
