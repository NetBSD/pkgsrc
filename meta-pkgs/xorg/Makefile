# $NetBSD: Makefile,v 1.1.1.1 2004/07/29 04:48:33 xtraeme Exp $

DISTNAME=	# empty
PKGNAME=	xorg-${XORG_VER}
CATEGORIES=	meta-pkgs x11
MASTER_SITES=	${MASTER_SITE_XORG}
DISTFILES=	# empty

MAINTAINER=	xtraeme@NetBSD.org
HOMEPAGE=	http://www.x.org/
COMMENT=	X.org meta-package

DEPENDS=	xorg-imake>=${XORG_VER}:../../x11/xorg-imake
DEPENDS+=	xorg-libs>=${XORG_VER}:../../x11/xorg-libs
DEPENDS+=	xorg-server>=${XORG_VER}:../../x11/xorg-server
DEPENDS+=	xorg-clients>=${XORG_VER}:../../x11/xorg-clients
DEPENDS+=	xorg-fontsEncodings>=${XORG_VER}:../../fonts/xorg-fontsEncodings
DEPENDS+=	xorg-fonts100dpi>=${XORG_VER}:../../fonts/xorg-fonts100dpi
DEPENDS+=	xorg-fonts75dpi>=${XORG_VER}:../../fonts/xorg-fonts75dpi
DEPENDS+=	xorg-fontsMisc>=${XORG_VER}:../../fonts/xorg-fontsMisc
DEPENDS+=	xorg-fontsCyrillic>=${XORG_VER}:../../fonts/xorg-fontsCyrillic
DEPENDS+=	xorg-fontsTruetype>=${XORG_VER}:../../fonts/xorg-fontsTruetype
DEPENDS+=	xorg-fontsType1>=${XORG_VER}:../../fonts/xorg-fontsType1
DEPENDS+=	xorg-docs>=${XORG_VER}:../../misc/xorg-docs

NO_BUILD=		# defined
NO_BUILDLINK=		# defined
NO_CHECKSUM=		# defined
NO_MTREE=		# defined
NO_XORG_TARGETS=	# defined
NO_CONFIGURE=		# defined

do-install:

.include "Makefile.common"
.include "../../mk/bsd.pkg.mk"
