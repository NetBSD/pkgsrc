# $NetBSD: Makefile,v 1.2 2004/07/29 06:36:33 xtraeme Exp $

DISTNAME=	X11R6.7.0-src1
PKGNAME=	xorg-fontsType1-${XORG_VER}
CATEGORIES=	fonts x11
MASTER_SITES=	${MASTER_SITE_XORG}

MAINTAINER=	xtraeme@NetBSD.org
HOMEPAGE=	http://www.x.org/
COMMENT=	X.org Type1 fonts

BUILD_DEPENDS=	xorg-clients>=6.7.0:../../x11/xorg-clients
DEPENDS+=	xorg-fontsEncodings>=6.7.0:../../x11/xorgs-fontsEncodings

CHECK_X11_TYPE=		# defined
XBUILD_DIRS=		fonts/encodings fonts/scaled/Type1
XINSTALL_DIRS=		fonts/scaled/Type1

FILESDIR=	${.CURDIR}/../../fonts/xorg-fontsEncodings/files

SUBST_CLASSES=		font
SUBST_STAGE.font=	post-patch
SUBST_FILES.font=	 config/cf/X11.tmpl
SUBST_SED.font=		-e "s,FCCACHE = \$$(BINDIR)/fc-cache,FCCACHE=${LOCALBASE}/bin/fc-cache,"
SUBST_MESSAGE.font=	"Fixing path of fc-cache."

.include "../../meta-pkgs/xorg/Makefile.common"
.include "../../mk/bsd.pkg.mk"
