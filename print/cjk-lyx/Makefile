# $NetBSD: Makefile,v 1.13 2004/11/13 22:04:53 jlam Exp $

DISTNAME=	lyx-${LYX_VERS}
PKGNAME=	cjk-${DISTNAME}
PKGREVISION=	4
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

USE_LANGUAGES=		c c++
USE_BUILDLINK3=		yes
USE_PKGLOCALEDIR=	yes
USE_PERL5=		yes
USE_X11=		yes
GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes

.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/xpm/buildlink3.mk"
.include "../../x11/xforms/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
