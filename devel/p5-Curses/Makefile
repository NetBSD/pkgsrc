# $NetBSD: Makefile,v 1.21 2004/04/25 03:29:44 minskim Exp $
# FreeBSD Id: Makefile,v 1.8 1998/04/04 13:58:26 vanilla Exp
#

DISTNAME=	Curses-1.05
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5cur
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Curses/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://theory.uwinnipeg.ca/CPAN/data/Curses/Curses.html
COMMENT=	Perl5 module for terminal screen handling and optimization

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_NCURSES=	# needs libpanel

USE_BUILDLINK3=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Curses/.packlist

MAKE_PARAMS=	PANELS

pre-configure:
	@${LN} -sf ${WRKSRC}/hints/c-netbsd.ncurses.h ${WRKSRC}/c-config.h

.include "../../devel/ncurses/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
