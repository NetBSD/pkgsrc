# $NetBSD: Makefile,v 1.1 2001/06/10 05:41:25 explorer Exp $

DISTNAME=	WeakRef-0.01
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/LUKKA/}

MAINTAINER=	packages@netbsd.org
COMMENT=	Provide weak references in Perl

USE_PERL5=	#defined
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/WeakRef/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../mk/bsd.pkg.mk"
