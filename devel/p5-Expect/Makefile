# $NetBSD: Makefile,v 1.3 2000/07/16 21:32:47 thorpej Exp $

DISTNAME=	Expect.pm-1.07
PKGNAME=	p5-expect-1.07
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Expect/}

MAINTAINER=	packages@netbsd.org

USE_PERL5=	YES

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PREFIX}/bin/perl Makefile.PL

.include "../../mk/bsd.pkg.mk"
