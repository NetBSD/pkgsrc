# $NetBSD: Makefile,v 1.16 2004/10/03 00:14:50 tv Exp $

DISTNAME=		g2-0.49a
PKGREVISION=		3
CATEGORIES=		graphics
MASTER_SITES=		http://g2.sourceforge.net/pub/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://g2.sourceforge.net/
COMMENT=		Powerful, easy to use 2D graphics library

GNU_CONFIGURE=		yes
USE_X11=		yes
USE_LIBTOOL=		yes

USE_BUILDLINK3=		yes
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/G2/.packlist
PERL5_CONFIGURE=	no
PERL5_CONFIGURE_DIRS=	${WRKSRC}/g2_perl
BUILD_DIRS=		${WRKSRC} ${WRKSRC}/g2_perl

post-configure: perl5-configure

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/g2
	cd ${WRKSRC} && ${INSTALL_DATA} doc/g2_ref.txt COPYING README	\
		${PREFIX}/share/doc/g2
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/g2
	cd ${WRKSRC}/demo && ${INSTALL_DATA} *.c *.f *.inc  \
		${PREFIX}/share/examples/g2

.include "../../graphics/gd/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
