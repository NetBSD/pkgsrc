# $NetBSD: Makefile,v 1.1.1.1 2001/09/27 04:37:07 jlam Exp $

DISTNAME=		Test-Simple-0.17
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=		packages@netbsd.org
COMMENT=		perl5 module with a simple framework for writing tests

DEPENDS+=		p5-Test-Harness-*:../../devel/p5-Test-Harness

USE_PERL5=		# defined
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Test/Simple/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../mk/bsd.pkg.mk"
