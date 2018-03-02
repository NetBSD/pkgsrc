# $NetBSD: Makefile,v 1.25 2018/03/02 14:27:00 adam Exp $

DISTNAME=	libdvbpsi-1.3.2
CATEGORIES=	multimedia
MASTER_SITES=	http://www.videolan.org/pub/libdvbpsi/${PKGVERSION_NOREV}/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.videolan.org/
COMMENT=	PSI decoder and generator library for MPEG2 and DVB streams
LICENSE=	gnu-lgpl-v2.1

USE_TOOLS+=		gmake
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
PKGCONFIG_OVERRIDE=	libdvbpsi.pc.in

LIBS.SunOS+=	-lsocket -lnsl

CONFIG_GUESS_OVERRIDE=	.auto/config.guess
CONFIG_SUB_OVERRIDE=	.auto/config.sub

.include "../../mk/bsd.pkg.mk"
