# $NetBSD: Makefile,v 1.5 2012/12/16 01:52:34 obache Exp $

DISTNAME=	ykclient-2.9
PKGREVISION=	1
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
