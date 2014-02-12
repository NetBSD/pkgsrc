# $NetBSD: Makefile,v 1.11 2014/02/12 23:18:37 tron Exp $

DISTNAME=	ykclient-2.11
PKGREVISION=	1
CATEGORIES=	security
MASTER_SITES=	http://yubico.github.io/yubico-c-client/releases/

MAINTAINER=	pettai@NetBSD.org
HOMEPAGE=	http://yubico.github.io/yubico-c-client/
COMMENT=	Libraries for online validation of Yubikey OTPs

LICENSE=	modified-bsd

BUILD_DEPENDS+=		help2man-[0-9]*:../../converters/help2man

MAKE_JOBS_SAFE=	no

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes

.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
