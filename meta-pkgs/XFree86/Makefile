# $NetBSD: Makefile,v 1.1.1.1 2004/01/24 08:52:27 xtraeme Exp $

DISTNAME=	# empty
PKGNAME=	XFree86-${XF_VER}
CATEGORIES=	meta-pkgs x11
MASTER_SITES=	${MASTER_SITE_XFREE}
DISTFILES=	# empty

MAINTAINER=	xfree86@blef.org
HOMEPAGE=	http://www.xfree86.org/
COMMENT=	XFree86 meta-package

DEPENDS=	imake>=4.3.0:../../wip/imake
DEPENDS+=	XFree86-libs>=4.3.0:../../wip/XFree86-libs
DEPENDS+=	XFree86-clients>=4.3.0:../../wip/XFree86-clients
DEPENDS+=	XFree86-server>=4.3.0:../../wip/XFree86-server
DEPENDS+=	XFree86-docs>=4.3.0:../../wip/XFree86-docs
DEPENDS+=	XFree86-man>=4.3.0:../../wip/XFree86-man
DEPENDS+=	XFree86-fontsEncodings>=4.3.0:../../wip/XFree86-fontsEncodings
DEPENDS+=	XFree86-fontsCyrillic>=4.3.0:../../wip/XFree86-fontsCyrillic
DEPENDS+=	XFree86-fontsMisc>=4.3.0:../../wip/XFree86-fontsMisc
DEPENDS+=	XFree86-fonts100dpi>=4.3.0:../../wip/XFree86-fonts100dpi
DEPENDS+=	XFree86-fonts75dpi>=4.3.0:../../wip/XFree86-fonts75dpi
DEPENDS+=	XFree86-fontserver>=4.3.0:../../wip/XFree86-fontserver
DEPENDS+=	XFree86-fontsScalable>=4.3.0:../../wip/XFree86-fontsScalable

USE_BUILDLINK2=		yes
NO_BUILD=		# defined
NO_CHECKSUM=		# defined
NO_MTREE=		# defined
NO_XFREE86_TARGETS=	# defined
NO_CONFIGURE=		# defined

do-install:
	# empty

.include "../../wip/XFree86/Makefile.common"
.include "../../mk/bsd.pkg.mk"
