# $NetBSD: Makefile,v 1.11 2005/09/28 20:52:21 rillig Exp $

DISTNAME=	XFree86-${XF_VER}-src-4
PKGNAME=	XFree86-fontsCyrillic-${XF_VER}
PKGREVISION=	1
CATEGORIES=	fonts x11
MASTER_SITES=	${MASTER_SITE_XFREE}
EXTRACT_SUFX=	.tgz

MAINTAINER=	xtraeme@NetBSD.org
HOMEPAGE=	http://www.xfree86.org/
COMMENT=	XFree86 Cyrillic fonts

NO_XFREE86_TARGETS=	yes
WRKSRC=			${WRKDIR}/xc/fonts/bdf/cyrillic

.include "../../fonts/XFree86-fontsEncodings/Makefile.common"
.include "../../meta-pkgs/XFree86/Makefile.common"
.include "../../mk/bsd.pkg.mk"
