# $NetBSD: Makefile,v 1.3 2001/04/14 21:43:41 jtb Exp $

DISTNAME=	Storable-1.0.11
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Storable/}

MAINTAINER=	packages@netbsd.org
COMMENT=	Perl extension module for persistent data storage

USE_PERL5=	#defined
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/Storable/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../mk/bsd.pkg.mk"

