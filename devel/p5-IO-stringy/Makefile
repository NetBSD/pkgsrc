# $NetBSD: Makefile,v 1.9 2001/10/18 15:20:17 veego Exp $
#

DISTNAME=	IO-stringy-1.220
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5isr
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=IO/}

MAINTAINER=	packages@netbsd.org
COMMENT=	Perl class for I/O on in-core objects like strings and arrays

USE_PERL5=	# defined
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/IO-stringy/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../mk/bsd.pkg.mk"
