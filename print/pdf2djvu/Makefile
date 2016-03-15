# $NetBSD: Makefile,v 1.40 2016/03/15 13:15:29 ryoon Exp $
#

DISTNAME=	pdf2djvu-0.9.4
CATEGORIES=	print
MASTER_SITES=	https://bitbucket.org/jwilk/pdf2djvu/downloads/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://jwilk.net/software/pdf2djvu
COMMENT=	Creates DjVu files from PDF files
LICENSE=	gnu-gpl-v2

DEPENDS+=	djvulibre-tools-[0-9]*:../../graphics/djvulibre-tools

WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}
GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c++
USE_TOOLS+=		pkg-config gmake intltool msgfmt xgettext
CONFIGURE_ARGS+=	--localedir=${PREFIX}/${PKGLOCALEDIR}/locale

.include "../../graphics/djvulibre-lib/buildlink3.mk"
.include "../../print/poppler/buildlink3.mk"
.include "../../print/poppler-includes/buildlink3.mk"
.include "../../graphics/GraphicsMagick/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
