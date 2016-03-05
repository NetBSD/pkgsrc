# $NetBSD: Makefile,v 1.38 2016/03/05 11:29:17 jperkin Exp $
#

DISTNAME=	pdf2djvu-0.9.3
PKGREVISION=	1
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
USE_LANGUAGES=		c++ c
USE_TOOLS+=		pkg-config gmake intltool msgfmt xgettext gsed:run
TOOLS_DEPENDS.gsed=	gsed>=4.2:../../textproc/gsed
CONFIGURE_ARGS+=	--localedir=${PREFIX}/${PKGLOCALEDIR}/locale

.include "../../mk/bsd.prefs.mk"
.if !empty(MACHINE_PLATFORM:MNetBSD-5*) || ${OPSYS} == "MirBSD"
BUILDLINK_TRANSFORM+=	rm:-Werror=overloaded-virtual
.endif

.include "../../graphics/djvulibre-lib/buildlink3.mk"
.include "../../print/poppler/buildlink3.mk"
.include "../../print/poppler-includes/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../graphics/GraphicsMagick/buildlink3.mk"
.include "../../devel/pstreams/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
