# $NetBSD: Makefile,v 1.18 2021/06/06 01:17:17 markd Exp $

.include "../../print/texlive/Makefile.common"

PKGNAME=	gsftopkk-1.19.2
PKGREVISION=	12
CATEGORIES=	print

HOMEPAGE=	https://math.berkeley.edu/~vojta/gsftopk.html
COMMENT=	Tool to convert bitmaps to .pk format

EXTRACT_ELEMENTS+=	${DISTNAME}/texk/gsftopk

WRKSRC=		${WRKDIR}/${DISTNAME}/texk/gsftopk

USE_TOOLS+=		gs:run
CONFIGURE_ARGS+=	--with-system-kpathsea
CPPFLAGS+=		-DGS_PATH='"${TOOLS_PATH.gs}"'
INFO_FILES=		yes

TEX_TEXMF_DIRS+=	${PREFIX}/share/texmf-dist

BUILDLINK_API_DEPENDS.kpathsea+= kpathsea>=6.2.1
.include "../../print/kpathsea/buildlink3.mk"
.include "../../print/kpathsea/texmf.mk"
.include "../../mk/bsd.pkg.mk"
