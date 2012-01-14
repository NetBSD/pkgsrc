# $NetBSD: Makefile,v 1.3 2012/01/14 03:43:36 hans Exp $
#

DISTNAME=	pdf2djvu_0.7.7
PKGNAME=	${DISTNAME:S/_/-/}
PKGREVISION=	1
CATEGORIES=	print
MASTER_SITES=	http://pdf2djvu.googlecode.com/files/

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://code.google.com/p/pdf2djvu/
COMMENT=	pdf2djvu creates DjVu files from PDF files
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	djvulibre-tools-[0-9]*:../../graphics/djvulibre-tools
DEPENDS+=	gsed>=4.2:../../textproc/gsed

WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}
GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c++ c
USE_TOOLS+=		pkg-config gmake intltool msgfmt xgettext gsed

# We really need GNU sed not NetBSD's GNUish sed
.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "NetBSD"
TOOLS_PLATFORM.gsed=	# empty
.endif

.include "../../graphics/djvulibre-lib/buildlink3.mk"
.include "../../print/poppler/buildlink3.mk"
.include "../../print/poppler-includes/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../graphics/GraphicsMagick/buildlink3.mk"
.include "../../devel/pstreams/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
