# $NetBSD: Makefile,v 1.3 2003/06/02 01:21:25 jschauma Exp $
#

DISTNAME=	libicq2000-0.3.2
PKGREVISION=	1
CATEGORIES=	chat
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=libicq2000/}

MAINTAINER=	tech-pkg@netbsd.org
HOMEPAGE=	http://libicq2000.sourceforge.net/
COMMENT=	Library for icq 2000/2001 clients

USE_BUILDLINK2=		YES
USE_LIBTOOL=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
GNU_CONFIGURE=		YES

.include "../../devel/libsigc++10/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
