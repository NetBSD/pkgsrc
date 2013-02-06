# $NetBSD: Makefile,v 1.6 2013/02/06 23:21:34 jperkin Exp $

DISTNAME=	ykclient-2.9
PKGREVISION=	2
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
