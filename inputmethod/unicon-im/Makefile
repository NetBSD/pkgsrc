# $NetBSD: Makefile,v 1.1.1.1 2002/06/15 09:29:14 shell Exp $

DISTNAME=	unicon-1.2
PKGNAME=	unicon-im-1.2
CATEGORIES=	inputmethod
MASTER_SITES=	http://www.opencjk.org/~yumj/download/

MAINTAINER=	rxg@netbsd.org
HOMEPAGE=	http://www.opencjk.org/~yumj/project-chinput.html
COMMENT=	libraries and modules of Unicon

USE_PTHREAD=	native pth
USE_LIBTOOL=	YES

GNU_CONFIGURE=	YES

.include "../../mk/pthread.buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
