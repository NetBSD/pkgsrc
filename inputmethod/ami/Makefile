# $NetBSD: Makefile,v 1.7 2003/07/17 21:43:32 grant Exp $
#

DISTNAME=	ami-1.0.11
PKGREVISION=	2
CATEGORIES=	korean inputmethod
MASTER_SITES=	http://www.kr.freebsd.org/~hwang/ami/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.kr.freebsd.org/~hwang/ami/
COMMENT=	Korean input method

USE_BUILDLINK2=	YES
GNU_CONFIGURE=	YES
DEPENDS+=	gtk+-1.2.*:../../x11/gtk

.include "../../graphics/gdk-pixbuf/buildlink2.mk"
.include "../../x11/gtk/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
