# $NetBSD: Makefile,v 1.3 2023/10/24 22:08:21 wiz Exp $

DISTNAME=	libmesode-0.10.1
PKGREVISION=	1
CATEGORIES=	chat
MASTER_SITES=	${MASTER_SITE_GITHUB:=profanity-im/}
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/boothj5/libmesode
COMMENT=	Fork of libstrophe for use with the Profanity XMPP client
LICENSE=	mit OR gnu-gpl-v3

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	autoconf automake autoreconf pkg-config
USE_LANGUAGES=	c c++

# Nasty things with macros.
FORTIFY_SUPPORTED=	no

PKGCONFIG_OVERRIDE+=	libmesode.pc.in

pre-configure:
	cd ${WRKSRC} && autoreconf -i

.include "../../textproc/expat/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
