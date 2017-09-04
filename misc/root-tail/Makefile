# $NetBSD: Makefile,v 1.12 2017/09/04 18:00:57 wiz Exp $
#

DISTNAME=	root-tail-0.0.10
PKGREVISION=	3
CATEGORIES=	misc x11
MASTER_SITES=	http://www.goof.com/pcg/marc/data/

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://www.goof.com/pcg/marc/root-tail.html
COMMENT=	Allows printing of text directly to the X11 root window

USE_IMAKE=	YES

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
