# $NetBSD: Makefile,v 1.6 2004/03/29 08:05:50 xtraeme Exp $
#

DISTNAME=	xaric-0.12.1
CATEGORIES=	chat
MASTER_SITES=	ftp://ftp.xaric.org/pub/xaric/	\
		http://www.xaric.org/downloads/

MAINTAINER=	xtraeme@NetBSD.org
HOMEPAGE=	http://www.xaric.org/
COMMENT=	IRC client similar to BitchX and ircII

USE_BUILDLINK3=	yes
GNU_CONFIGURE=	yes
USE_GNU_TOOLS+=	make

CONFIGURE_ARGS+=	--enable-optimize

.include "../../mk/bsd.pkg.mk"
