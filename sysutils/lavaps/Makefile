# $NetBSD: Makefile,v 1.6 2000/09/06 16:09:50 jlam Exp $
#

DISTNAME=	lavaps-1.10
CATEGORIES=	sysutils x11
MASTER_SITES=	http://www.isi.edu/~johnh/SOFTWARE/LAVAPS/

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://www.isi.edu/~johnh/SOFTWARE/LAVAPS/

DEPENDS+=	tk-8.3.2:../../x11/tk

USE_X11=	YES
GNU_CONFIGURE=	YES
CONFIGURE_ARGS=	--with-additional-includes='-I${LOCALBASE}/include' \
		--with-additional-libs='-L${LOCALBASE}/lib' \
		--with-tcl-ver=8.3.2 --with-tk-ver=8.3.2

.include "../../mk/bsd.pkg.mk"
