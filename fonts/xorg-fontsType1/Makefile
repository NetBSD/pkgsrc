# $NetBSD: Makefile,v 1.7 2004/10/08 03:35:25 xtraeme Exp $

DISTNAME=	X11R${XORG_VER}-src1
PKGNAME=	xorg-fontsType1-${XORG_VER}
CATEGORIES=	fonts x11
MASTER_SITES=	${MASTER_SITE_XORG}

MAINTAINER=	xtraeme@NetBSD.org
HOMEPAGE=	http://www.x.org/
COMMENT=	X.org Type1 fonts

BUILD_DEPENDS=	xorg-clients>=${XORG_VER}:../../x11/xorg-clients
DEPENDS+=	xorg-fontsEncodings>=${XORG_VER}:../../fonts/xorg-fontsEncodings

XBUILD_DIRS=	fonts/encodings fonts/scaled/Type1
XINSTALL_DIRS=	fonts/scaled/Type1

FILESDIR=	${.CURDIR}/../../fonts/xorg-fontsEncodings/files

SUBST_CLASSES=		font
SUBST_STAGE.font=	post-patch
SUBST_FILES.font=	 config/cf/X11.tmpl
SUBST_SED.font=		-e "s,FCCACHE = \$$(BINDIR)/fc-cache,FCCACHE=${LOCALBASE}/bin/fc-cache,"
SUBST_MESSAGE.font=	"Fixing path of fc-cache."

SUBST_CLASSES=		scaled
SUBST_STAGE.scaled=	post-configure
SUBST_FILES.scaled=	fonts/scaled/Type1/Makefile
SUBST_SED.scaled=	-e "s,/usr/X11R6,${LOCALBASE},g"

.include "../../meta-pkgs/xorg/Makefile.common"
.include "../../mk/bsd.pkg.mk"
