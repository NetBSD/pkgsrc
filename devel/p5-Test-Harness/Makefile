# $NetBSD: Makefile,v 1.6 2002/03/15 12:28:49 martti Exp $

DISTNAME=		Test-Harness-2.02
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5tha
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=		shell@shellhung.org
COMMENT=		perl5 module for testing

USE_BUILDLINK_ONLY=	YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Test/Harness/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../lang/perl5/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
