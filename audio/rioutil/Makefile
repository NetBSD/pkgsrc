# $NetBSD: Makefile,v 1.5 2002/11/26 22:02:59 schmonz Exp $
#

DISTNAME=	rioutil-1.2b
PKGNAME=	rioutil-1.2.1
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
# depends on -r1.6 of sys/dev/usb/urio.c
ONLY_FOR_PLATFORM+=	NetBSD-1.5Z-* NetBSD-1.5Z[A-Z]-*

.include "../../audio/id3lib/buildlink2.mk"
.include "../../devel/libusb/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
