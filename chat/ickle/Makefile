# $NetBSD: Makefile,v 1.6 2004/02/14 17:21:34 jlam Exp $

DISTNAME=	ickle-0.3.2
PKGREVISION=	2
CATEGORIES=	chat
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=ickle/}

MAINTAINER=	soren@blef.org
HOMEPAGE=	http://ickle.sourceforge.net/
COMMENT=	Simplistic gtk+ icq client

USE_BUILDLINK2= YES
USE_LIBTOOL=    YES
GNU_CONFIGURE=  YES

.include "../../chat/libicq2000/buildlink2.mk"
.include "../../x11/gtk--/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
