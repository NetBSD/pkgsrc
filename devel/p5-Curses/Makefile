# $NetBSD: Makefile,v 1.5 1999/07/06 07:59:20 jlam Exp $
# FreeBSD Id: Makefile,v 1.8 1998/04/04 13:58:26 vanilla Exp
#

DISTNAME=	Curses-1.02
PKGNAME=	p5-Curses-1.02
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Curses/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://theory.uwinnipeg.ca/CPAN/data/Curses/Curses.html

DEPENDS=	ncurses-4.2:../../devel/ncurses

USE_PERL5=	YES

do-configure:
		@${LN} -sf ${WRKSRC}/hints/c-netbsd.ncurses.h ${WRKSRC}/c-config.h
		@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PREFIX}/bin/perl Makefile.PL

.include "../../mk/bsd.pkg.mk"
