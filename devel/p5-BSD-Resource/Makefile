# $NetBSD: Makefile,v 1.2 2001/10/18 15:20:12 veego Exp $

DISTNAME=		BSD-Resource-1.10
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5bsd
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=BSD/}

MAINTAINER=		packages@NetBSD.org
HOMEPAGE=		http://iki.fi/jhi/
COMMENT=		BSD::Resource - Perl interface to BSD process resources library

USE_PERL5=		# defined
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/BSD/Resource/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../mk/bsd.pkg.mk"
