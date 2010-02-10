# $NetBSD: Makefile,v 1.30 2010/02/10 19:17:44 joerg Exp $

DISTNAME=	lyx-${LYX_VERS}
PKGNAME=	cjk-${DISTNAME}
PKGREVISION=	11
CATEGORIES=	print
MASTER_SITES=	ftp://ftp.lyx.org/pub/lyx/stable/ \
		ftp://gd.tuwien.ac.at/publishing/tex/lyx/stable/

PATCH_SITES=	ftp://stone.phys.pusan.ac.kr/pub/CJK-LyX/
PATCHFILES=	CJK-LyX-${LYX_VERS}-patch
PATCH_DIST_ARGS=-d ${WRKSRC}/.. --forward --quiet -p0

MAINTAINER=	rxg@NetBSD.org
HOMEPAGE=	http://cellular.phys.pusan.ac.kr/cjk.html
COMMENT=	Multibyte version of LyX

LYX_VERS=	1.2.0

CONFLICTS=	lyx-[0-9]*

DEPENDS+=	ispell-base-[0-9]*:../../textproc/ispell-base

TEX_ACCEPTED=		teTeX3
USE_LANGUAGES=		c c++
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		perl:run msgfmt
GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes

REPLACE_PERL+=		lib/reLyX/reLyXmain.pl
REPLACE_PYTHON+=	lib/scripts/*.py lib/scripts/listerrors

.include "../../lang/python/application.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../x11/xforms/buildlink3.mk"
.include "../../mk/tex.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
