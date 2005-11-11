# $NetBSD: Makefile,v 1.18 2005/11/11 18:50:24 tonio Exp $

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

TEX_ACCEPTED=		teTeX1 teTeX2 teTeX3
USE_LANGUAGES=		c c++
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		perl:run
GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes

.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/xpm/buildlink3.mk"
.include "../../x11/xforms/buildlink3.mk"
.include "../../mk/tex.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
