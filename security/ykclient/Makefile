# $NetBSD: Makefile,v 1.9 2013/09/14 07:02:32 pettai Exp $

DISTNAME=	ykclient-2.11
CATEGORIES=	security
MASTER_SITES=	http://yubico.github.io/yubico-c-client/releases/

MAINTAINER=	pettai@NetBSD.org
HOMEPAGE=	http://yubico.github.io/yubico-c-client/
COMMENT=	Libraries for online validation of Yubikey OTPs

LICENSE=	modified-bsd

MAKE_JOBS_SAFE=	no

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes

.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
