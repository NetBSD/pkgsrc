# $NetBSD: Makefile,v 1.16 1998/07/31 14:32:15 kleink Exp $

DISTNAME=	tiff-v3.4beta037
PKGNAME=	tiff-3.4
CATEGORIES=	graphics
MASTER_SITES=   ftp://ftp.sgi.com/graphics/tiff/ \
		ftp://ftp.gwdg.de/pub/grafik/sgi/tiff/ \
		ftp://ftp.fu-berlin.de/unix/graphics/tiff/
EXTRACT_SUFX=	-tar.gz

MAINTAINER=	tron@netbsd.org

BUILD_DEPENDS=	${PREFIX}/bin/libtool:../../devel/libtool
DEPENDS+=	jpeg-6b:../../graphics/jpeg

HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	--noninteractive --site ${FILESDIR}
CONFIGURE_ENV+=		PREFIX=${PREFIX} GCOPTS=-O
MAKE_ENV+=		INSTALL_MAN="${INSTALL_MAN}" LN="${LN}"

.include "../../mk/bsd.pkg.mk"
