# $NetBSD: Makefile,v 1.1 2002/03/07 12:10:29 cjs Exp $

DISTNAME=	Test-Unit-0.14
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5tun
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=	cjs@netbsd.org
COMMENT=	Perl extension module for Unit Tests.

USE_BUILDLINK_ONLY=	YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Test/Unit/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../lang/perl5/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
