# $NetBSD: Makefile,v 1.3 2001/11/22 09:33:09 martti Exp $

DISTNAME=		Test-Harness-1.26
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5tha
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=		shell@shellhung.org
COMMENT=		perl5 module for testing

USE_PERL5=		# defined
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Test/Harness/.packlist

post-patch:
	@perl -pi.orig -e 'm.INSTALLDIRS.&&s,.,,sg' ${WRKSRC}/Makefile.PL

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../mk/bsd.pkg.mk"
