# $NetBSD: Makefile,v 1.34 2011/08/14 12:59:47 obache Exp $

DISTNAME=		g2-0.50
PKGREVISION=		7
CATEGORIES=		graphics
MASTER_SITES=		http://g2.sourceforge.net/pub/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://g2.sourceforge.net/
COMMENT=		Powerful, easy to use 2D graphics library

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes

PERL5_PACKLIST=		auto/G2/.packlist
PERL5_CONFIGURE=	no
PERL5_CONFIGURE_DIRS=	${WRKSRC}/g2_perl
BUILD_DIRS=		. g2_perl
TEST_TARGET=		# none

INSTALLATION_DIRS=	share/doc/g2 share/examples/g2

post-configure: perl5-configure

post-install:
	cd ${WRKSRC} && ${INSTALL_DATA} doc/g2_ref.txt COPYING README	\
		${DESTDIR}${PREFIX}/share/doc/g2
	cd ${WRKSRC}/demo && ${INSTALL_DATA} *.c *.f *.inc  \
		${DESTDIR}${PREFIX}/share/examples/g2

.include "../../graphics/gd/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
