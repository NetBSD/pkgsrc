# $NetBSD: Makefile,v 1.1.1.1 1999/10/31 21:20:11 hubertf Exp $
#

DISTNAME=	lavaps-1.8
CATEGORIES=	sysutils x11
MASTER_SITES=	http://www.isi.edu/~johnh/SOFTWARE/LAVAPS/

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://www.isi.edu/~johnh/SOFTWARE/LAVAPS/

DEPENDS+=	tcl-8.0.5:../../lang/tcl80
DEPENDS+=	tk-8.0.5:../../x11/tk80

GNU_CONFIGURE=	YES
CONFIGURE_ARGS+=--with-additional-includes='-I${LOCALBASE}/include/tcl8.0 -I${LOCALBASE}/include/tk8.0' \
		--with-additional-libs='-L${LOCALBASE}/lib'

.include "../../mk/bsd.pkg.mk"
