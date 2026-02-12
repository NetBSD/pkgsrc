# $NetBSD: Makefile,v 1.2 2026/02/12 19:49:30 schmonz Exp $

DISTNAME=	mlmmj-1.7.0
CATEGORIES=	mail
MASTER_SITES=	https://codeberg.org/mlmmj/mlmmj/releases/download/RELEASE_1_7_0/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	uebayasi@NetBSD.org
HOMEPAGE=	https://mlmmj.org/
COMMENT=	Mailing list management made joyful
LICENSE=	mit

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-tests
USE_TOOLS=		autoconf automake autoreconf pkg-config
USE_PKGLOCALEDIR=	yes

pre-configure:
	cd ${WRKSRC} && autoreconf -fiv

.include "../../converters/libiconv/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
