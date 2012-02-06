# $NetBSD: Makefile,v 1.5 2012/02/06 12:41:22 wiz Exp $
#

DISTNAME=	pdf2djvu_0.7.7
PKGNAME=	${DISTNAME:S/_/-/}
PKGREVISION=	2
CATEGORIES=	print
MASTER_SITES=	http://pdf2djvu.googlecode.com/files/

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://code.google.com/p/pdf2djvu/
COMMENT=	pdf2djvu creates DjVu files from PDF files
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	djvulibre-tools-[0-9]*:../../graphics/djvulibre-tools

WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}
GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c++ c
USE_TOOLS+=		pkg-config gmake intltool msgfmt xgettext gsed:run
TOOLS_DEPENDS.gsed=	gsed>=4.2:../../textproc/gsed

.include "../../graphics/djvulibre-lib/buildlink3.mk"
.include "../../print/poppler/buildlink3.mk"
.include "../../print/poppler-includes/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../graphics/GraphicsMagick/buildlink3.mk"
.include "../../devel/pstreams/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
