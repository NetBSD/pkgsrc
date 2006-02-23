# $NetBSD: Makefile,v 1.16 2006/02/23 17:36:19 wiz Exp $
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

.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
