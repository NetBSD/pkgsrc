# $NetBSD: Makefile,v 1.2 2001/10/18 15:20:18 veego Exp $

DISTNAME=	Params-Validate-0.04
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5pva
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/D/DR/DROLSKY/}

MAINTAINER=	packages@netbsd.org
COMMENT=	Validate method/function parameters

USE_PERL5=	#defined
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/Params/Validate/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../mk/bsd.pkg.mk"

