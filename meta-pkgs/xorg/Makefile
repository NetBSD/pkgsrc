# $NetBSD: Makefile,v 1.10 2006/01/24 07:32:22 wiz Exp $

DISTNAME=	# empty
PKGNAME=	xorg-${XORG_VER}
PKGREVISION=	2
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
DEPENDS+=	xterm-[0-9]*:../../x11/xterm
DEPENDS+=	xorg-fontsEncodings>=${XORG_VER}:../../fonts/xorg-fontsEncodings
DEPENDS+=	xorg-fonts100dpi>=${XORG_VER}:../../fonts/xorg-fonts100dpi
DEPENDS+=	xorg-fonts75dpi>=${XORG_VER}:../../fonts/xorg-fonts75dpi
DEPENDS+=	xorg-fontsMisc>=${XORG_VER}:../../fonts/xorg-fontsMisc
DEPENDS+=	xorg-fontsCyrillic>=${XORG_VER}:../../fonts/xorg-fontsCyrillic
DEPENDS+=	xorg-fontsTruetype>=${XORG_VER}:../../fonts/xorg-fontsTruetype
DEPENDS+=	xorg-fontsType1>=${XORG_VER}:../../fonts/xorg-fontsType1
DEPENDS+=	xorg-docs>=${XORG_VER}:../../misc/xorg-docs

NO_BUILD=		yes
NO_CHECKSUM=		yes
NO_MTREE=		yes
NO_XORG_TARGETS=	yes
USE_DIRS+=		xorg-1.0
NO_CONFIGURE=		yes

do-install:

.include "Makefile.common"

.include "../../mk/bsd.pkg.mk"
