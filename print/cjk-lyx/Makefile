# $NetBSD: Makefile,v 1.8 2004/01/03 18:49:51 reed Exp $

DISTNAME=	lyx-${LYX_VERS}
PKGNAME=	cjk-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	print
MASTER_SITES=	ftp://ftp.lyx.org/pub/lyx/stable/ \
		ftp://gd.tuwien.ac.at/publishing/tex/lyx/stable/ \
		ftp://ftp.sdsc.edu/pub/other/lyx/stable/

PATCH_SITES=	ftp://stone.phys.pusan.ac.kr/pub/CJK-LyX/
PATCHFILES=	CJK-LyX-${LYX_VERS}-patch
PATCH_DIST_ARGS=-d ${WRKSRC}/.. --forward --quiet -p0

MAINTAINER=	rxg@ms25.url.com.tw
HOMEPAGE=	http://cellular.phys.pusan.ac.kr/cjk.html
COMMENT=	Multibyte version of LyX

LYX_VERS=	1.2.0

CONFLICTS=	lyx-[0-9]*

DEPENDS+=	ispell-base-[0-9]*:../../textproc/ispell-base
DEPENDS+=	teTeX-bin>=1.0.7nb1:../../print/teTeX-bin

USE_BUILDLINK2=		yes
USE_PKGLOCALEDIR=	yes
USE_PERL5=		yes
USE_X11=		yes
USE_GCC_SHLIB=		yes
GNU_CONFIGURE=		yes

USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
LIBTOOL_OVERRIDE+=	${WRKSRC}/sigc++/libtool

.include "../../graphics/jpeg/buildlink2.mk"
.include "../../graphics/xpm/buildlink2.mk"
.include "../../x11/xforms/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
