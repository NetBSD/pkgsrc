# $NetBSD: Makefile,v 1.11 2011/09/08 21:10:26 wiz Exp $

DISTNAME=	libdvbpsi-0.2.1
CATEGORIES=	multimedia
MASTER_SITES=	http://www.videolan.org/pub/libdvbpsi/${PKGVERSION_NOREV}/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.videolan.org/
COMMENT=	PSI decoder and generator library for MPEG2 and DVB streams
LICENSE=	gnu-lgpl-v2.1

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=		gmake
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
PKGCONFIG_OVERRIDE=	libdvbpsi.pc.in

.include "../../mk/bsd.pkg.mk"
