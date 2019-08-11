# $NetBSD: Makefile,v 1.34 2019/08/11 13:21:00 wiz Exp $
#

DISTNAME=	fntsample-5.2
PKGREVISION=	4
CATEGORIES=	fonts
MASTER_SITES=	${MASTER_SITE_GITHUB:=eugmes/}
GITHUB_TAG=	release/${PKGVERSION_NOREV}

BLOCKS_TXT=	Blocks-20190308.txt
DISTFILES=	${DEFAULT_DISTFILES} ${BLOCKS_TXT}
SITES.${BLOCKS_TXT}=	-http://unicode.org/Public/UNIDATA/Blocks.txt

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/eugmes/fntsample/
COMMENT=	Make font samples, similar to Unicode charts, showing Unicode coverage
LICENSE=	gnu-gpl-v3

USE_TOOLS+=	pkg-config gmake perl:run msgfmt
USE_CMAKE=	yes

WRKSRC=		${WRKDIR}/${DISTNAME:S/-/-release-/}

REPLACE_PERL=	pdfoutline.pl

CMAKE_ARGS+=	-DUNICODE_BLOCKS=${WRKDIR}/${BLOCKS_TXT}

.include "../../devel/pango/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
