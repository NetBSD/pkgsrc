# $NetBSD: Makefile,v 1.2 1998/07/13 16:55:59 tv Exp $
# FreeBSD Id: Makefile,v 1.8 1998/04/04 13:58:26 vanilla Exp
#

DISTNAME=	Curses-1.02
PKGNAME=	p5-Curses-1.02
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Curses

MAINTAINER=	packages@netbsd.org

DEPENDS=	ncurses-1.9.9g:../../devel/ncurses

USE_PERL5=	YES

do-configure:
		@${LN} -sf ${WRKSRC}/hints/c-netbsd.ncurses.h ${WRKSRC}/c-config.h
		@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PREFIX}/bin/perl Makefile.PL

.include "../../mk/bsd.pkg.mk"
