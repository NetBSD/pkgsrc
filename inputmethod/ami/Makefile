# $NetBSD: Makefile,v 1.11 2004/04/25 04:16:43 xtraeme Exp $
#

DISTNAME=	ami-1.0.11
PKGREVISION=	3
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
