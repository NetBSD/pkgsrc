# $NetBSD: Makefile,v 1.3 2001/10/18 15:20:38 veego Exp $
#

DISTNAME=		SHA-1.2
PKGNAME=		p5-SHA-1.2
SVR4_PKGNAME=		p5sha
CATEGORIES=		security perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=SHA/}

MAINTAINER=		packages@netbsd.org
COMMENT=		perl5 interface to the SHA1 algorithm

USE_PERL5=		# defined
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/SHA/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../mk/bsd.pkg.mk"
