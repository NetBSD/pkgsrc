# $NetBSD: Makefile,v 1.13 2005/06/01 18:02:46 jlam Exp $
#

DISTNAME=	wily-0.13.41
CATEGORIES=	editors plan9
MASTER_SITES=	ftp://ftp.cs.yorku.ca/pub/wily/src/old/
EXTRACT_SUFX=	.tgz

MAINTAINER=	agc@NetBSD.org
HOMEPAGE=	http://www.cs.yorku.ca/~oz/wily/
COMMENT=	Unix/X11 clone of the Plan9 acme editor/environment

GNU_CONFIGURE=	yes

DEPENDS+=	libXgFonts-1.0:../../fonts/Xg

.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
