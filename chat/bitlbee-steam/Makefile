# $NetBSD: Makefile,v 1.2 2020/03/08 16:48:54 wiz Exp $

DISTNAME=	bitlbee-steam-1.4.2
PKGREVISION=	1
CATEGORIES=	chat
MASTER_SITES=	${MASTER_SITE_GITHUB:=bitlbee/}
GITHUB_PROJECT=	bitlbee-steam
GITHUB_RELEASE=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.bitlbee.org/
COMMENT=	Steam protocol plugin for BitlBee
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config
USE_LIBTOOL=	yes

.include "../../chat/bitlbee/buildlink3.mk"
.include "../../security/libgcrypt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
