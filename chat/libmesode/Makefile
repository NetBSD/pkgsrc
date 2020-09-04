# $NetBSD: Makefile,v 1.1 2020/09/04 10:13:16 nia Exp $

DISTNAME=	libmesode-0.9.3
CATEGORIES=	chat
MASTER_SITES=	${MASTER_SITE_GITHUB:=profanity-im/}
GITHUB_RELEASE=	${PKGVERSION_NOREV}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/boothj5/libmesode
COMMENT=	Fork of libstrophe for use with the Profanity XMPP client
LICENSE=	mit OR gnu-gpl-v3

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	autoconf automake autoreconf pkg-config
USE_LANGUAGES=	c c++

PKGCONFIG_OVERRIDE+=	libmesode.pc.in

pre-configure:
	cd ${WRKSRC} && autoreconf -i

.include "../../textproc/expat/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
