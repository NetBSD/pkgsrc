# $NetBSD: Makefile,v 1.28 2023/10/24 22:08:24 wiz Exp $
#

DISTNAME=	xaric-0.13.6
PKGREVISION=	4
CATEGORIES=	chat
MASTER_SITES=	http://xaric.org/software/xaric/releases/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://xaric.org/
COMMENT=	IRC client similar to BitchX and ircII

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/termcap.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
