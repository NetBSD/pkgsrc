# $NetBSD: Makefile,v 1.2 2001/02/08 22:21:51 jtb Exp $

DISTNAME=		g2-0.40
CATEGORIES=		graphics
MASTER_SITES=		ftp://g2.sourceforge.net/pub/g2/

MAINTAINER=		jtb@netbsd.org
HOMEPAGE=		http://g2.sourceforge.net/

GNU_CONFIGURE=		yes
USE_X11=		yes
ALL_TARGET=		depend all

USE_PERL5=		#defined
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/G2/.packlist

post-configure:
	cd ${WRKSRC}/g2_perl; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

post-build:
	cd ${WRKSRC}/g2_perl && ${MAKE}

post-install:
	cd ${WRKSRC}/g2_perl && ${MAKE} install

.include "../../mk/bsd.pkg.mk"
