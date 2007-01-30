# $NetBSD: Makefile,v 1.17 2007/01/30 23:13:37 joerg Exp $
#

DISTNAME=	wily-0.13.41
PKGREVISION=	1
CATEGORIES=	editors plan9
MASTER_SITES=	ftp://ftp.cs.yorku.ca/pub/wily/src/old/
EXTRACT_SUFX=	.tgz

MAINTAINER=	agc@NetBSD.org
HOMEPAGE=	http://www.cs.yorku.ca/~oz/wily/
COMMENT=	Unix/X11 clone of the Plan9 acme editor/environment

GNU_CONFIGURE=	yes
CONFIGURE_HAS_MANDIR=	no

DEPENDS+=	libXgFonts>=1.0nb1:../../fonts/Xg

.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
