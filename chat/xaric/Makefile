# $NetBSD: Makefile,v 1.2 2003/01/31 01:10:46 salo Exp $
#

DISTNAME=	xaric-0.12.1
CATEGORIES=	chat
MASTER_SITES=	ftp://ftp.xaric.org/pub/xaric/	\
		http://www.xaric.org/downloads/

MAINTAINER=	jrp@hispabsd.org
HOMEPAGE=	http://www.xaric.org/
COMMENT=	UNIX irc client similer to BitchX or ircII

USE_BUILDLINK2=	YES
GNU_CONFIGURE=	YES
USE_GMAKE=	YES

CONFIGURE_ARGS+=	--enable-optimize

.include "../../mk/bsd.pkg.mk"
