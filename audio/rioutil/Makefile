# $NetBSD: Makefile,v 1.3 2002/09/10 23:33:20 schmonz Exp $
#

DISTNAME=	rioutil-1.2a4
PKGNAME=	rioutil-1.2.0.4
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=rioutil/}

MAINTAINER=	schmonz@netbsd.org
HOMEPAGE=	http://rioutil.sourceforge.net/
COMMENT=	program and library to interface with Rio 600, 800, Nike psa[play

USE_BUILDLINK2=		# defined
USE_LIBTOOL=		# defined
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig
GNU_CONFIGURE=		# defined
CONFIGURE_ARGS+=	--with-libusb
CONFIG_GUESS_OVERRIDE=	${WRKSRC}/config.guess
CONFIG_SUB_OVERRIDE=	${WRKSRC}/config.sub

ONLY_FOR_PLATFORM=	Darwin-*-* Linux-*-* NetBSD-1.[6-9]*-*

.include "../../audio/id3lib/buildlink2.mk"
.include "../../devel/libusb/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
