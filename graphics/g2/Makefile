# $NetBSD: Makefile,v 1.6 2001/05/03 21:17:23 jtb Exp $

DISTNAME=		g2-0.40
PKGNAME=		g2-0.40nb1
CATEGORIES=		graphics
MASTER_SITES=		ftp://g2.sourceforge.net/pub/g2/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://g2.sourceforge.net/
COMMENT=		Powerful, easy to use 2D graphics library

GNU_CONFIGURE=		yes
USE_X11=		yes
USE_LIBTOOL=		yes

ALL_TARGET=		depend all

USE_PERL5=		#defined
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/G2/.packlist

post-configure:
	cd ${WRKSRC}/g2_perl; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

post-build:
	cd ${WRKSRC}/g2_perl && ${MAKE}

post-install:
	cd ${WRKSRC}/g2_perl && ${MAKE} install
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/g2
	cd ${WRKSRC} && ${INSTALL_DATA} doc/g2_ref.txt COPYING README	\
		${PREFIX}/share/doc/g2
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/g2
	cd ${WRKSRC}/demo && ${INSTALL_DATA} demo_f.f g2_test.c penguin.c \
		simple_PS.c simple_X11.c ${PREFIX}/share/examples/g2

.include "../../mk/bsd.pkg.mk"
