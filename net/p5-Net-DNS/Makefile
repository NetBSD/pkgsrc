# $NetBSD: Makefile,v 1.1.1.1 1999/11/08 01:06:49 hubertf Exp $
#

DISTNAME=		Net-DNS-0.12
PKGNAME=		p5-Net-DNS-0.12
CATEGORIES=		net perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Net/}

MAINTAINER=		hubertf@netbsd.org

USE_PERL5=		YES

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PREFIX}/bin/perl Makefile.PL

.include "../../mk/bsd.pkg.mk"
