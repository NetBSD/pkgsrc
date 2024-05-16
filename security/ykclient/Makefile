# $NetBSD: Makefile,v 1.41 2024/05/16 06:15:32 wiz Exp $

DISTNAME=	ykclient-2.15
PKGREVISION=	13
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=Yubico/}
GITHUB_PROJECT=	yubico-c-client
GITHUB_TAG=	${DISTNAME}

MAINTAINER=	pettai@NetBSD.org
HOMEPAGE=	https://developers.yubico.com/yubico-c-client/
COMMENT=	Libraries for online validation of Yubikey OTPs
LICENSE=	modified-bsd

TOOL_DEPENDS+=		help2man-[0-9]*:../../converters/help2man

MAKE_JOBS_SAFE=	no

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake pkg-config autoconf automake autoreconf

pre-configure:
	cd ${WRKSRC} && autoreconf -if

.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
