# $NetBSD: Makefile,v 1.41 2017/08/16 20:21:07 wiz Exp $

DISTNAME=	libebml-1.3.4
CATEGORIES=	devel
MASTER_SITES=	http://dl.matroska.org/downloads/libebml/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	salo@NetBSD.org
HOMEPAGE=	https://sourceforge.net/projects/ebml/
COMMENT=	Extensible Binary Meta Language support library
LICENSE=	gnu-lgpl-v2.1

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake

PKGCONFIG_OVERRIDE=	libebml.pc.in

GNU_CONFIGURE=		yes

.include "../../mk/bsd.pkg.mk"
