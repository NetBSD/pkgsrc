# $NetBSD: Makefile,v 1.2 2001/02/17 17:50:00 wiz Exp $
#

DISTNAME=		SHA-1.2
PKGNAME=		p5-SHA-1.2
CATEGORIES=		security perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=SHA/}

MAINTAINER=		packages@netbsd.org
COMMENT=		perl5 interface to the SHA1 algorithm

USE_PERL5=		# defined
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/SHA/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../mk/bsd.pkg.mk"
