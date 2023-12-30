# $NetBSD: Makefile,v 1.29 2023/12/30 01:39:27 zafer Exp $
#

DISTNAME=	xaric-0.13.6
PKGREVISION=	4
CATEGORIES=	chat
MASTER_SITES=	https://xaric.org/software/xaric/releases/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://xaric.org/
COMMENT=	IRC client similar to BitchX and ircII

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/termcap.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
