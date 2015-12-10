# $NetBSD: Makefile,v 1.1 2015/12/10 23:04:25 ryoon Exp $

DISTNAME=	stlink-1.1.0
CATEGORIES=	cross
MASTER_SITES=	${MASTER_SITE_GITHUB:=texane/}
GITHUB_PROJECT=	stlink
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://github.com/texane/stlink
COMMENT=	STM32 Discovery STLINKv1/v2 programming tool
LICENSE=	modified-bsd

USE_TOOLS+=	automake pkg-config
GNU_CONFIGURE=	yes

pre-configure:
	cd ${WRKSRC} && \
	aclocal; autoheader; automake -a --foreign -i; autoconf

.include "../../devel/libusb1/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
