# $NetBSD: Makefile,v 1.5 2003/06/02 01:19:08 jschauma Exp $
#

DISTNAME=	ami-1.0.11
PKGREVISION=	1
CATEGORIES=	korean inputmethod
MASTER_SITES=	http://www.kr.freebsd.org/~hwang/ami/

MAINTAINER=	tech-pkg@netbsd.org
HOMEPAGE=	http://www.kr.freebsd.org/~hwang/ami/
COMMENT=	Korean input method

USE_BUILDLINK2=	YES
GNU_CONFIGURE=	YES
DEPENDS+=	gtk+-1.2.*:../../x11/gtk

.include "../../graphics/gdk-pixbuf/buildlink2.mk"
.include "../../x11/gtk/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
