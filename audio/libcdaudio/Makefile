# $NetBSD: Makefile,v 1.12 2002/08/25 19:21:50 jlam Exp $
#

DISTNAME=	libcdaudio-0.99.6
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=libcdaudio/}

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://libcdaudio.sourceforge.net
COMMENT=	Multi-platform CD player development library

USE_BUILDLINK_ONLY=	YES
GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

.include "../../mk/bsd.pkg.mk"
