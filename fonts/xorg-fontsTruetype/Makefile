# $NetBSD: Makefile,v 1.4 2004/07/30 08:31:23 xtraeme Exp $

DISTNAME=	X11R6.7.0-src1
PKGNAME=	xorg-fontsTruetype-${XORG_VER}
CATEGORIES=	fonts x11
MASTER_SITES=	${MASTER_SITE_XORG}

MAINTAINER=	xtraeme@NetBSD.org
HOMEPAGE=	http://www.x.org/
COMMENT=	X.org Truetype fonts

BUILD_DEPENDS=	xorg-clients>=6.7.0:../../x11/xorg-clients
BUILD_DEPENDS+=	fontconfig-[0-9]*:../../fonts/fontconfig
DEPENDS+=	xorg-fontsEncodings>=6.7.0:../../fonts/xorg-fontsEncodings

CONFLICTS=	vera-ttf-[0-9]*

XBUILD_DIRS=		fonts/encodings fonts/scaled/TTF
XINSTALL_DIRS=		fonts/scaled/TTF

FILESDIR=	${.CURDIR}/../../fonts/xorg-fontsEncodings/files

SUBST_CLASSES=		font
SUBST_STAGE.font=	post-patch
SUBST_FILES.font=	config/cf/X11.tmpl
SUBST_SED.font=		-e "s,FCCACHE = \$$(BINDIR)/fc-cache,FCCACHE=${LOCALBASE}/bin/fc-cache,"
SUBST_MESSAGE.font=	"Fixing path of fc-cache."

.include "../../meta-pkgs/xorg/Makefile.common"
.include "../../mk/bsd.pkg.mk"
