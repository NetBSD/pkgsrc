# $NetBSD: Makefile,v 1.19 2004/04/08 14:12:50 drochner Exp $
#

DISTNAME=	libcdaudio-0.99.10
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=libcdaudio/}

MAINTAINER=	rh@NetBSD.org
HOMEPAGE=	http://libcdaudio.sourceforge.net/
COMMENT=	Multi-platform CD player development library

USE_BUILDLINK2=		YES
GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
PKGCONFIG_OVERRIDE=	libcdaudio.pc.in

.include "../../mk/bsd.pkg.mk"
