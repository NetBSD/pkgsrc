# $NetBSD: Makefile,v 1.3 2003/06/01 02:41:44 grant Exp $
#

DISTNAME=	xaric-0.12.1
CATEGORIES=	chat
MASTER_SITES=	ftp://ftp.xaric.org/pub/xaric/	\
		http://www.xaric.org/downloads/

MAINTAINER=	jrp@hispabsd.org
HOMEPAGE=	http://www.xaric.org/
COMMENT=	IRC client similar to BitchX and ircII

USE_BUILDLINK2=	YES
GNU_CONFIGURE=	YES
USE_GMAKE=	YES

CONFIGURE_ARGS+=	--enable-optimize

.include "../../mk/bsd.pkg.mk"
