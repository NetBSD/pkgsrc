# $NetBSD: Makefile,v 1.2 2002/08/31 02:06:17 wiz Exp $
#

DISTNAME=	rioutil-1.1.2alpha
PKGNAME=	rioutil-1.1.2.0.1
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

# on NetBSD, we need a recent urio.c
ONLY_FOR_PLATFORM=	NetBSD-1.5Z-* NetBSD-1.5Z[A-Z]-* NetBSD-1.[6-9]*-* \
			Darwin-*-* Linux-*-*

.include "../../audio/id3lib/buildlink2.mk"
.include "../../devel/libusb/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
