# $NetBSD: Makefile,v 1.3 2020/04/22 04:39:48 nia Exp $

DISTNAME=	bitlbee-discord-0.4.3
CATEGORIES=	chat
MASTER_SITES=	${MASTER_SITE_GITHUB:=sm00th/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/sm00th/bitlbee-discord
COMMENT=	Discord protocol plugin for BitlBee
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	autoreconf autoconf automake
USE_TOOLS+=	pkg-config
GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

pre-configure:
	cd ${WRKSRC} && ./autogen.sh

.include "../../chat/bitlbee/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
