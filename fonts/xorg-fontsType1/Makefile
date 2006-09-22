# $NetBSD: Makefile,v 1.16 2006/09/22 21:53:57 joerg Exp $

DISTNAME=	X11R${XORG_VER}-src1
PKGNAME=	xorg-fontsType1-${XORG_VER}
PKGREVISION=	3
CATEGORIES=	fonts x11
MASTER_SITES=	${MASTER_SITE_XORG}

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	http://www.x.org/
COMMENT=	X.org Type1 fonts

USE_TOOLS+=	imake

DEPENDS+=	xorg-fontsEncodings>=${XORG_VER}:../../fonts/xorg-fontsEncodings

XBUILD_DIRS=	fonts/encodings fonts/scaled/Type1
XINSTALL_DIRS=	fonts/scaled/Type1
XEXTRACTS=	${XBUILD_DIRS}

SUBST_CLASSES+=		font
SUBST_STAGE.font=	post-patch
SUBST_FILES.font=	 config/cf/X11.tmpl
SUBST_SED.font=		-e "s,FCCACHE = \$$(BINDIR)/fc-cache,FCCACHE=${LOCALBASE}/bin/fc-cache,"
SUBST_MESSAGE.font=	Fixing path of fc-cache.

SUBST_CLASSES+=		scaled
SUBST_STAGE.scaled=	post-configure
SUBST_FILES.scaled=	fonts/scaled/Type1/Makefile
SUBST_SED.scaled=	-e "s,/usr/X11R6,${LOCALBASE},g"

FONTS_DIRS.type1=	${X11ROOT_PREFIX}/lib/X11/fonts/Type1
FONTS_DIRS.x11=		${X11ROOT_PREFIX}/lib/X11/fonts/Type1

.include "../../fonts/xorg-fontsEncodings/Makefile.common"
.include "../../mk/bsd.pkg.mk"
