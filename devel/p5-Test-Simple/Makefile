# $NetBSD: Makefile,v 1.4 2001/11/22 09:37:56 martti Exp $

DISTNAME=		Test-Simple-0.33
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5tsi
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=		packages@netbsd.org
COMMENT=		perl5 module with a simple framework for writing tests

DEPENDS+=		p5-Test-Harness-[0-9]*:../../devel/p5-Test-Harness

USE_PERL5=		# defined
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Test/Simple/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../mk/bsd.pkg.mk"
