# $NetBSD: Makefile,v 1.2 2002/08/01 05:48:15 jlam Exp $

DISTNAME=	unicon-1.2
PKGNAME=	unicon-im-1.2
CATEGORIES=	inputmethod
MASTER_SITES=	http://www.opencjk.org/~yumj/download/

MAINTAINER=	rxg@netbsd.org
HOMEPAGE=	http://www.opencjk.org/~yumj/project-chinput.html
COMMENT=	libraries and modules of Unicon

USE_LIBTOOL=	YES
PTHREAD_OPTS+=	require

GNU_CONFIGURE=	YES

.include "../../mk/pthread.buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
