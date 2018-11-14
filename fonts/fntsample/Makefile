# $NetBSD: Makefile,v 1.32 2018/11/14 22:21:27 kleink Exp $
#

DISTNAME=	fntsample-5.2
PKGREVISION=	2
CATEGORIES=	fonts
MASTER_SITES=	${MASTER_SITE_GITHUB:=eugmes/}
GITHUB_TAG=	release/${PKGVERSION_NOREV}

DISTFILES=	${DEFAULT_DISTFILES} Blocks.txt
SITES.Blocks.txt=	http://unicode.org/Public/UNIDATA/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/eugmes/fntsample/
COMMENT=	Make font samples, similar to Unicode charts, showing Unicode coverage
LICENSE=	gnu-gpl-v3

USE_TOOLS+=	pkg-config gmake perl:run msgfmt
USE_CMAKE=	yes

WRKSRC=		${WRKDIR}/${DISTNAME:S/-/-release-/}

REPLACE_PERL=	pdfoutline.pl

CMAKE_ARGS+=	-DUNICODE_BLOCKS=${WRKDIR}/Blocks.txt

.include "../../devel/pango/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
