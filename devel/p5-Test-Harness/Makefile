# $NetBSD: Makefile,v 1.7.2.1 2002/06/23 18:44:47 jlam Exp $

DISTNAME=		Test-Harness-2.24
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
