# $NetBSD: Makefile,v 1.9 2001/10/18 15:20:15 veego Exp $

DISTNAME=	Expect-1.11
PKGNAME=	p5-expect-1.11
SVR4_PKGNAME=	p5exp
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Expect/}

MAINTAINER=	packages@netbsd.org
COMMENT=	perl version of the TCL "expect" tool

DEPENDS+=	p5-IO-stty-[0-9]*:../../devel/p5-IO-Stty
DEPENDS+=	p5-IO-tty-[0-9]*:../../devel/p5-IO-Tty

USE_PERL5=	# defined
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/Expect/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../mk/bsd.pkg.mk"
