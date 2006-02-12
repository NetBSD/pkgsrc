# $NetBSD: Makefile,v 1.14 2006/02/12 15:29:18 xtraeme Exp $

DISTNAME=	X11R${XORG_VER}-src1
PKGNAME=	xorg-fontsTruetype-${XORG_VER}
PKGREVISION=	2
CATEGORIES=	fonts x11
MASTER_SITES=	${MASTER_SITE_XORG}

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	http://www.x.org/
COMMENT=	X.org Truetype fonts

BUILD_DEPENDS+=	fontconfig-[0-9]*:../../fonts/fontconfig
DEPENDS+=	xorg-fontsEncodings>=${XORG_VER}:../../fonts/xorg-fontsEncodings

XBUILD_DIRS=	fonts/encodings fonts/scaled/TTF
XINSTALL_DIRS=	fonts/scaled/TTF
XEXTRACTS=	${XBUILD_DIRS} extras/fonts

SUBST_CLASSES+=		font
SUBST_STAGE.font=	post-patch
SUBST_FILES.font=	config/cf/X11.tmpl
SUBST_SED.font=		-e "s,FCCACHE = \$$(BINDIR)/fc-cache,FCCACHE=${LOCALBASE}/bin/fc-cache,"
SUBST_MESSAGE.font=	"Fixing path of fc-cache."

SUBST_CLASSES+=		TTF
SUBST_STAGE.TTF=	post-configure
SUBST_FILES.TTF=	fonts/scaled/TTF/Makefile
SUBST_SED.TTF=		-e "s,/usr/X11R6,${LOCALBASE},g"

.include "../../fonts/xorg-fontsEncodings/Makefile.common"
.include "../../mk/bsd.pkg.mk"
