# $NetBSD: Makefile,v 1.1.1.1 2002/11/12 17:13:07 itojun Exp $
#

DISTNAME=	ami-1.0.11
CATEGORIES=	inputmethod
MASTER_SITES=	http://www.kr.freebsd.org/~hwang/ami/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.kr.freebsd.org/~hwang/ami/
COMMENT=	Korean input method

GNU_CONFIGURE=	YES
DEPENDS+=	gtk+-1.2.*:../../x11/gtk

.include "../../x11/gtk/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
