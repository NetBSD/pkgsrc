# $NetBSD: Makefile,v 1.18 2005/02/21 20:26:14 hubertf Exp $
#

DISTNAME=	lavaps-1.20
PKGNAME=	lavaps-1.20
CATEGORIES=	sysutils x11
MASTER_SITES=	http://www.isi.edu/~johnh/SOFTWARE/LAVAPS/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.isi.edu/~johnh/SOFTWARE/LAVAPS/
COMMENT=	Lava lamp of currently running processes

DEPENDS+=	tk>=8.3.2:../../x11/tk83
USE_PERL5=	build

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}
USE_X11=	# defined
GNU_CONFIGURE=	# defined
CONFIGURE_ARGS=	--with-additional-includes='-I${LOCALBASE}/include' \
		--with-additional-libs='-L${LOCALBASE}/lib' \
		--with-tcl-ver=8.3.2 --with-tk-ver=8.3.2 \
		--with-tcltk-lib-suffix-type=nodot

.include "../../mk/bsd.pkg.mk"
