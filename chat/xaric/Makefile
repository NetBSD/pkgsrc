# $NetBSD: Makefile,v 1.1.1.1 2002/12/19 12:16:14 grant Exp $
#

DISTNAME=	xaric-0.12.0
CATEGORIES=	chat
MASTER_SITES=	ftp://ftp.xaric.org/pub/xaric/

MAINTAINER=	jrp@hispabsd.org
HOMEPAGE=	http://www.xaric.org/
COMMENT=	UNIX irc client similer to BitchX or ircII

USE_BUILDLINK2=	YES
GNU_CONFIGURE=	YES
USE_GMAKE=	YES
USE_X11=	YES

CONFIGURE_ARGS+=	--enable-optimize

.include "../../mk/bsd.pkg.mk"
