# $NetBSD: Makefile,v 1.20 2005/04/05 10:44:51 wiz Exp $
#

DISTNAME=	lavaps-1.20
CATEGORIES=	sysutils x11
MASTER_SITES=	http://www.isi.edu/~johnh/SOFTWARE/LAVAPS/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.isi.edu/~johnh/SOFTWARE/LAVAPS/
COMMENT=	Lava lamp of currently running processes

USE_PERL5=	build

USE_X11=	YES
GNU_CONFIGURE=	YES
CONFIGURE_ARGS=	--with-additional-includes='-I${LOCALBASE}/include' \
		--with-additional-libs='-L${LOCALBASE}/lib' \
		--with-tcl-ver=8.3.2 --with-tk-ver=8.3.2 \
		--with-tcltk-lib-suffix-type=nodot

.include "../../x11/tk83/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
