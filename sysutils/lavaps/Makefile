# $NetBSD: Makefile,v 1.10 2001/10/31 02:03:29 hubertf Exp $
#

DISTNAME=	lavaps-1.20
PKGNAME=	lavaps-1.20
CATEGORIES=	sysutils x11
MASTER_SITES=	http://www.isi.edu/~johnh/SOFTWARE/LAVAPS/

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://www.isi.edu/~johnh/SOFTWARE/LAVAPS/
COMMENT=	Lava lamp of currently running processes

DEPENDS+=	tk>=8.3.2:../../x11/tk
WRKSRC=		${WRKDIR}/${PKGNAME}

USE_X11=	# defined
GNU_CONFIGURE=	# defined
CONFIGURE_ARGS=	--with-additional-includes='-I${LOCALBASE}/include' \
		--with-additional-libs='-L${LOCALBASE}/lib' \
		--with-tcl-ver=8.3.2 --with-tk-ver=8.3.2 \
		--with-tcltk-lib-suffix-type=nodot

.include "../../mk/bsd.pkg.mk"
