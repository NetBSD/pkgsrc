# $NetBSD: Makefile,v 1.1.1.1 2002/08/28 19:16:47 seb Exp $

DISTNAME=	Math-Bezier-0.01
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Math/}

MAINTAINER=	packages@netbsd.org
COMMENT=	Perl module for the solution of Bezier curves

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Math/Bezier/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../lang/perl5/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
