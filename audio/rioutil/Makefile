# $NetBSD: Makefile,v 1.15 2004/10/03 00:13:09 tv Exp $
#

DISTNAME=	rioutil-1.4.6
PKGREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=rioutil/}

MAINTAINER=	schmonz@NetBSD.org
HOMEPAGE=	http://rioutil.sourceforge.net/
COMMENT=	Program and library to interface with Rio 600, 800, Nike psa[play

USE_BUILDLINK3=		yes
USE_LIBTOOL=		# defined
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig
GNU_CONFIGURE=		# defined
CONFIGURE_ARGS+=	--with-libusb

ONLY_FOR_PLATFORM=	Darwin-*-* Linux-*-* NetBSD-1.6*-* NetBSD-[2-9]*-*
# depends on -r1.6 of sys/dev/usb/urio.c
ONLY_FOR_PLATFORM+=	NetBSD-1.5Z-* NetBSD-1.5Z[A-Z]-*

.include "../../audio/id3lib/buildlink3.mk"
.include "../../devel/libusb/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
