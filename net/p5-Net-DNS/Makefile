# $NetBSD: Makefile,v 1.3 2001/02/17 18:19:21 wiz Exp $
#

DISTNAME=		Net-DNS-0.12
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		net perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=		hubertf@netbsd.org
COMMENT=		Net::DNS - Perl DNS Resolver Module

USE_PERL5=		# defined
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Net/DNS/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../mk/bsd.pkg.mk"
