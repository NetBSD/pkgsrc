# $NetBSD: Makefile,v 1.13 2002/10/20 23:30:50 seb Exp $
# FreeBSD Id: Makefile,v 1.8 1998/04/04 13:58:26 vanilla Exp
#

DISTNAME=	Curses-1.05
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5cur
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Curses/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://theory.uwinnipeg.ca/CPAN/data/Curses/Curses.html
COMMENT=	perl5 module for terminal screen handling and optimization

USE_NCURSES=	# needs libpanel.so

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Curses/.packlist

MAKE_PARAMS=	PANELS

pre-configure:
	@${LN} -sf ${WRKSRC}/hints/c-netbsd.ncurses.h ${WRKSRC}/c-config.h

.include "../../devel/ncurses/buildlink2.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
