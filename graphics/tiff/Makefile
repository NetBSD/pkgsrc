# $NetBSD: Makefile,v 1.14 1998/07/15 11:24:51 agc Exp $

DISTNAME=	tiff-v3.4beta037
PKGNAME=	tiff-3.4
CATEGORIES=	graphics
MASTER_SITES=   ftp://ftp.sgi.com/graphics/tiff/ \
		ftp://ftp.gwdg.de/pub/grafik/sgi/tiff/ \
		ftp://ftp.fu-berlin.de/unix/graphics/tiff/
EXTRACT_SUFX=	-tar.gz

MAINTAINER=	tron@netbsd.org

DEPENDS+=	jpeg-6b:../../graphics/jpeg

HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	--noninteractive --site ${FILESDIR}
CONFIGURE_ENV+=		PREFIX=${PREFIX}
MAKE_ENV+=		INSTALL_MAN="${INSTALL_MAN}" LN="${LN}"

.include "../../mk/bsd.pkg.mk"
