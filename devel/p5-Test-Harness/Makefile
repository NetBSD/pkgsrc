# $NetBSD: Makefile,v 1.8 2002/05/09 06:03:38 shell Exp $

DISTNAME=		Test-Harness-2.21
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5tha
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=		shell@netbsd.org
COMMENT=		perl5 module for testing

USE_BUILDLINK_ONLY=	YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Test/Harness/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../lang/perl5/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
