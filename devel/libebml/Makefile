# $NetBSD: Makefile,v 1.36 2015/01/04 23:22:37 wiz Exp $

DISTNAME=	libebml-1.3.1
CATEGORIES=	devel
MASTER_SITES=	http://dl.matroska.org/downloads/libebml/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	salo@NetBSD.org
HOMEPAGE=	http://sourceforge.net/projects/ebml/
COMMENT=	Extensible Binary Meta Language support library
LICENSE=	gnu-lgpl-v2.1

USE_LANGUAGES=		c++
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake

PKGCONFIG_OVERRIDE=	libebml.pc.in

GNU_CONFIGURE=		yes

.include "../../mk/bsd.pkg.mk"
