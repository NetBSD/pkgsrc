# $NetBSD: Makefile,v 1.13 2004/12/28 23:18:15 reed Exp $
#

DISTNAME=	ami-1.0.11
PKGREVISION=	5
CATEGORIES=	korean inputmethod
MASTER_SITES=	http://www.kr.freebsd.org/~hwang/ami/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.kr.freebsd.org/~hwang/ami/
COMMENT=	Korean input method

USE_BUILDLINK3=	YES
GNU_CONFIGURE=	YES

.include "../../graphics/gdk-pixbuf/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
