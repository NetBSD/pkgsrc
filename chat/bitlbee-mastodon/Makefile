# $NetBSD: Makefile,v 1.6 2021/12/08 16:03:26 adam Exp $

DISTNAME=	bitlbee-mastodon-1.4.5
PKGREVISION=	1
CATEGORIES=	chat
MASTER_SITES=	${MASTER_SITE_GITHUB:=kensanata/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://wiki.bitlbee.org/HowtoMastodon
COMMENT=	Mastodon protocol plugin for BitlBee
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	autoreconf autoconf automake
USE_TOOLS+=	pkg-config gmake gsed
GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

pre-configure:
	cd ${WRKSRC} && ${SH} ./autogen.sh

.include "../../chat/bitlbee/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
