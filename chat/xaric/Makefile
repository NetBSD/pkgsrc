# $NetBSD: Makefile,v 1.30 2024/03/17 17:51:22 nia Exp $
#

DISTNAME=	xaric-0.13.9
CATEGORIES=	chat
MASTER_SITES=	https://xaric.org/software/xaric/releases/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://xaric.org/
COMMENT=	IRC client similar to BitchX and ircII
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/termcap.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
