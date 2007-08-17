# $NetBSD: Makefile,v 1.19 2007/08/17 23:46:17 agc Exp $
#

DISTNAME=	wily-0.13.41
PKGREVISION=	1
CATEGORIES=	editors plan9
MASTER_SITES=	ftp://ftp.cse.yorku.ca/pub/wily/src/old/
EXTRACT_SUFX=	.tgz

MAINTAINER=	agc@NetBSD.org
HOMEPAGE=	http://www.cse.yorku.ca/~oz/wily/
COMMENT=	Unix/X11 clone of the Plan9 acme editor/environment

GNU_CONFIGURE=	yes
CONFIGURE_HAS_MANDIR=	no
PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	libXgFonts>=1.0nb1:../../fonts/Xg

.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
