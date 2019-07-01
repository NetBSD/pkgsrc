# $NetBSD: Makefile,v 1.24 2019/07/01 04:07:51 ryoon Exp $

DISTNAME=	ykclient-2.13
PKGREVISION=	11
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
USE_TOOLS+=		pkg-config

.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
