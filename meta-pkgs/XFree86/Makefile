# $NetBSD: Makefile,v 1.12 2006/01/24 07:32:20 wiz Exp $

DISTNAME=	# empty
PKGNAME=	XFree86-${XF_VER}
PKGREVISION=	1
CATEGORIES=	meta-pkgs x11
MASTER_SITES=	${MASTER_SITE_XFREE}
DISTFILES=	# empty

MAINTAINER=	xtraeme@NetBSD.org
HOMEPAGE=	http://www.xfree86.org/
COMMENT=	XFree86 meta-package

DEPENDS+=	XFree86-imake>=4.4.0:../../x11/XFree86-imake
DEPENDS+=	XFree86-libs>=4.4.0:../../x11/XFree86-libs
DEPENDS+=	XFree86-clients>=4.4.0:../../x11/XFree86-clients
DEPENDS+=	XFree86-server>=4.4.0:../../x11/XFree86-server
DEPENDS+=	XFree86-docs>=4.4.0:../../misc/XFree86-docs
DEPENDS+=	XFree86-man>=4.4.0:../../misc/XFree86-man
DEPENDS+=	XFree86-fontsEncodings>=4.4.0:../../fonts/XFree86-fontsEncodings
DEPENDS+=	XFree86-fontsCyrillic>=4.4.0:../../fonts/XFree86-fontsCyrillic
DEPENDS+=	XFree86-fontsMisc>=4.4.0:../../fonts/XFree86-fontsMisc
DEPENDS+=	XFree86-fonts100dpi>=4.4.0:../../fonts/XFree86-fonts100dpi
DEPENDS+=	XFree86-fonts75dpi>=4.4.0:../../fonts/XFree86-fonts75dpi
DEPENDS+=	XFree86-fontserver>=4.4.0:../../fonts/XFree86-fontserver
DEPENDS+=	XFree86-fontsScalable>=4.4.0:../../fonts/XFree86-fontsScalable

NO_BUILD=		yes
NO_CHECKSUM=		yes
NO_MTREE=		yes
NO_XFREE86_TARGETS=	yes
NO_CONFIGURE=		yes
USE_DIRS+=		XFree86-1.0

do-install:
	# empty

.include "Makefile.common"
.include "../../mk/bsd.pkg.mk"
