# $NetBSD: Makefile,v 1.3 2003/05/02 11:54:03 wiz Exp $ 

DISTNAME=	ickle-0.3.2
PKGREVISION=	1
CATEGORIES=	chat
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=ickle/}

MAINTAINER=	soren@blef.org
HOMEPAGE=	http://ickle.sourceforge.net/
COMMENT=	Simplistic gtk+ icq client

USE_BUILDLINK2= YES
USE_LIBTOOL=    YES
LIBTOOL_OVERRIDE=       ${WRKSRC}/libtool
GNU_CONFIGURE=  YES

.include "../../chat/libicq2000/buildlink2.mk"
.include "../../x11/gtk--/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
