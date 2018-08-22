# $NetBSD: Makefile,v 1.29 2018/08/22 09:45:06 wiz Exp $
#

DISTNAME=	fntsample-4.1
PKGREVISION=	5
CATEGORIES=	fonts
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=fntsample/}

DISTFILES=	${DEFAULT_DISTFILES} Blocks.txt
SITES.Blocks.txt=	http://unicode.org/Public/UNIDATA/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://fntsample.sourceforge.net/
COMMENT=	Make font samples, similar to Unicode charts, showing Unicode coverage
LICENSE=	gnu-gpl-v3

USE_TOOLS+=	pkg-config gmake perl:run msgfmt
REPLACE_PERL=	pdfoutline.pl
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--with-unicode-blocks=${WRKDIR}/Blocks.txt

.include "../../devel/pango/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
