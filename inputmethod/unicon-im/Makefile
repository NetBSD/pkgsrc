# $NetBSD: Makefile,v 1.3 2002/09/23 01:36:58 jlam Exp $

DISTNAME=	unicon-1.2
PKGNAME=	unicon-im-1.2
CATEGORIES=	inputmethod
MASTER_SITES=	http://www.opencjk.org/~yumj/download/

MAINTAINER=	rxg@netbsd.org
HOMEPAGE=	http://www.opencjk.org/~yumj/project-chinput.html
COMMENT=	libraries and modules of Unicon

USE_BUILDLINK2=	YES
USE_X11=	YES
USE_LIBTOOL=	YES
PTHREAD_OPTS+=	require

GNU_CONFIGURE=	YES

.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
