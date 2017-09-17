# $NetBSD: Makefile,v 1.42 2017/09/17 10:04:28 adam Exp $

DISTNAME=	libebml-1.3.5
CATEGORIES=	devel
MASTER_SITES=	http://dl.matroska.org/downloads/libebml/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	salo@NetBSD.org
HOMEPAGE=	https://sourceforge.net/projects/ebml/
COMMENT=	Extensible Binary Meta Language support library
LICENSE=	gnu-lgpl-v2.1

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes
PKGCONFIG_OVERRIDE=	libebml.pc.in

.include "../../mk/bsd.pkg.mk"
