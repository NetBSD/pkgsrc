# $NetBSD: Makefile,v 1.4 2001/10/18 15:20:31 veego Exp $
#

DISTNAME=		Net-DNS-0.12
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5ndn
CATEGORIES=		net perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=		hubertf@netbsd.org
COMMENT=		Net::DNS - Perl DNS Resolver Module

USE_PERL5=		# defined
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Net/DNS/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../mk/bsd.pkg.mk"
