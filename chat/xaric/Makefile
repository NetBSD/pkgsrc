# $NetBSD: Makefile,v 1.4 2003/08/28 20:05:16 xtraeme Exp $
#

DISTNAME=	xaric-0.12.1
CATEGORIES=	chat
MASTER_SITES=	ftp://ftp.xaric.org/pub/xaric/	\
		http://www.xaric.org/downloads/

MAINTAINER=	xtraeme@NetBSD.org
HOMEPAGE=	http://www.xaric.org/
COMMENT=	IRC client similar to BitchX and ircII

USE_BUILDLINK2=	YES
GNU_CONFIGURE=	YES
USE_GMAKE=	YES

CONFIGURE_ARGS+=	--enable-optimize

.include "../../mk/bsd.pkg.mk"
