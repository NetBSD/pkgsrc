# $NetBSD: Makefile,v 1.18 1998/08/20 15:50:00 agc Exp $

DISTNAME=	tiff-v3.4beta037
PKGNAME=	tiff-3.4
CATEGORIES=	graphics
MASTER_SITES=   ftp://ftp.sgi.com/graphics/tiff/ \
		ftp://ftp.gwdg.de/pub/grafik/sgi/tiff/ \
		ftp://ftp.fu-berlin.de/unix/graphics/tiff/
EXTRACT_SUFX=	-tar.gz

MAINTAINER=	tron@netbsd.org
HOMEPAGE=	http://home.earthlink.net/~ritter/tiff/

DEPENDS+=	jpeg-6b:../../graphics/jpeg

HAS_CONFIGURE=		yes
USE_LIBTOOL=		yes
CONFIGURE_ARGS+=	--noninteractive --site ${FILESDIR}
CONFIGURE_ENV+=		PREFIX=${PREFIX} GCOPTS=-O
MAKE_ENV+=		INSTALL_MAN="${INSTALL_MAN}" LN="${LN}"

.include "../../mk/bsd.pkg.mk"
