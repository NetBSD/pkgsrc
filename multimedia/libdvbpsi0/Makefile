# $NetBSD: Makefile,v 1.3 2020/01/26 17:31:46 rillig Exp $

DISTNAME=	libdvbpsi-0.2.2
CATEGORIES=	multimedia
MASTER_SITES=	http://www.videolan.org/pub/libdvbpsi/${PKGVERSION_NOREV}/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.videolan.org/
COMMENT=	PSI decoder and generator library for MPEG2 and DVB streams (v0.x)
LICENSE=	gnu-lgpl-v2.1

USE_TOOLS+=		gmake
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
PKGCONFIG_OVERRIDE=	libdvbpsi.pc.in

CONFIG_GUESS_OVERRIDE=	.auto/config.guess
CONFIG_SUB_OVERRIDE=	.auto/config.sub

LIBS.SunOS+=	-lsocket -lnsl

.include "../../mk/bsd.pkg.mk"
