# $NetBSD: Makefile,v 1.4 2021/02/16 09:53:37 nia Exp $

DISTNAME=	bitlbee-facebook-1.2.2
CATEGORIES=	chat
MASTER_SITES=	${MASTER_SITE_GITHUB:=bitlbee/}
GITHUB_PROJECT=	bitlbee-facebook
GITHUB_RELEASE=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.bitlbee.org/
COMMENT=	Facebook protocol plugin for BitlBee
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config
USE_LIBTOOL=	yes

.include "../../chat/bitlbee/buildlink3.mk"
.include "../../textproc/json-glib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
