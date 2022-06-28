# $NetBSD: Makefile,v 1.45 2022/06/28 11:33:53 wiz Exp $

DISTNAME=	fntsample-5.4
PKGREVISION=	2
CATEGORIES=	fonts
MASTER_SITES=	${MASTER_SITE_GITHUB:=eugmes/}
GITHUB_TAG=	release/${PKGVERSION_NOREV}

BLOCKS_TXT=		Blocks-20220122.txt
DISTFILES=		${DEFAULT_DISTFILES} ${BLOCKS_TXT}
SITES.${BLOCKS_TXT}=	-http://unicode.org/Public/UNIDATA/Blocks.txt

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/eugmes/fntsample/
COMMENT=	Make font samples, similar to Unicode charts, showing Unicode coverage
LICENSE=	gnu-gpl-v3

USE_TOOLS+=	pkg-config gmake perl:run msgfmt
USE_CMAKE=	yes

WRKSRC=		${WRKDIR}/${DISTNAME:S/-/-release-/}

REPLACE_PERL=	scripts/pdfoutline.pl scripts/pdf-extract-outline.pl

CMAKE_ARGS+=	-DUNICODE_BLOCKS=${WRKDIR}/${BLOCKS_TXT}

.include "../../devel/pango/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
