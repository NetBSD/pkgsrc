# $NetBSD: Makefile,v 1.2 2000/07/16 17:11:18 hubertf Exp $

DISTNAME=	IO-Stty-.02
PKGNAME=	p5-IO-stty-0.02
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=IO/}

MAINTAINER=	packages@netbsd.org

USE_PERL5=	YES

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PREFIX}/bin/perl Makefile.PL

.include "../../mk/bsd.pkg.mk"
