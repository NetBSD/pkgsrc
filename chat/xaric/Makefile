# $NetBSD: Makefile,v 1.7 2004/05/07 01:14:47 xtraeme Exp $
#

DISTNAME=	xaric-0.12.1
CATEGORIES=	chat
MASTER_SITES=	ftp://ftp.xaric.org/pub/xaric/	\
		http://www.xaric.org/downloads/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.xaric.org/
COMMENT=	IRC client similar to BitchX and ircII

USE_BUILDLINK3=	yes
GNU_CONFIGURE=	yes
USE_GNU_TOOLS+=	make

CONFIGURE_ARGS+=	--enable-optimize

.include "../../mk/bsd.pkg.mk"
