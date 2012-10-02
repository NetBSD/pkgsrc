# $NetBSD: Makefile,v 1.23 2012/10/02 23:48:07 asau Exp $
#

DISTNAME=	rioutil-1.5.0
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=rioutil/}

MAINTAINER=	schmonz@NetBSD.org
HOMEPAGE=	http://rioutil.sourceforge.net/
COMMENT=	Program and library to interface with Rio 600, 800, Nike psa[play

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-libusb

ONLY_FOR_PLATFORM=	Darwin-*-* Linux-*-* NetBSD-1.6*-* NetBSD-[2-9]*-*
# depends on -r1.6 of sys/dev/usb/urio.c
ONLY_FOR_PLATFORM+=	NetBSD-1.5Z-* NetBSD-1.5Z[A-Z]-*
ONLY_FOR_PLATFORM+=	DragonFly-*-* FreeBSD-*-* OpenBSD-*-*

.include "../../audio/id3lib/buildlink3.mk"
.include "../../devel/libusb/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
