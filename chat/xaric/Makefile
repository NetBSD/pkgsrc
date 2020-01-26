# $NetBSD: Makefile,v 1.26 2020/01/26 17:30:49 rillig Exp $
#

DISTNAME=	xaric-0.13.6
PKGREVISION=	3
CATEGORIES=	chat
MASTER_SITES=	http://xaric.org/software/xaric/releases/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://xaric.org/
COMMENT=	IRC client similar to BitchX and ircII

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake

CONFIGURE_ARGS+=	--enable-optimize

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/termcap.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
