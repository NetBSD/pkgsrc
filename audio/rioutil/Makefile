# $NetBSD: Makefile,v 1.11 2004/03/22 03:58:00 kristerw Exp $
#

DISTNAME=	rioutil-1.3.3
PKGREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=rioutil/}

MAINTAINER=	schmonz@NetBSD.org
HOMEPAGE=	http://rioutil.sourceforge.net/
COMMENT=	Program and library to interface with Rio 600, 800, Nike psa[play

USE_BUILDLINK2=		# defined
USE_LIBTOOL=		# defined
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig
GNU_CONFIGURE=		# defined
CONFIGURE_ARGS+=	--with-libusb

ONLY_FOR_PLATFORM=	Darwin-*-* Linux-*-* NetBSD-1.[6-9]*-* NetBSD-[2-9]*-*
# depends on -r1.6 of sys/dev/usb/urio.c
ONLY_FOR_PLATFORM+=	NetBSD-1.5Z-* NetBSD-1.5Z[A-Z]-*

.include "../../audio/id3lib/buildlink2.mk"
.include "../../devel/libusb/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
