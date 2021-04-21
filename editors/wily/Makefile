# $NetBSD: Makefile,v 1.23 2021/04/21 08:05:56 wiz Exp $

DISTNAME=	wily-0.13.42
CATEGORIES=	editors plan9
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=wily/}
EXTRACT_SUFX=	.tar.gz

MAINTAINER=	agc@NetBSD.org
HOMEPAGE=	http://www.cse.yorku.ca/~oz/wily/
COMMENT=	Unix/X11 clone of the Plan9 acme editor/environment
LICENSE=	artistic

GNU_CONFIGURE=		yes
CONFIGURE_HAS_MANDIR=	no

DEPENDS+=	libXgFonts>=1.0nb1:../../fonts/Xg

.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
