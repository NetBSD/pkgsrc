# $NetBSD: Makefile,v 1.1.1.1 2002/03/01 02:32:35 abs Exp $

DISTNAME=	Class-ObjectTemplate-0.4
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5cot
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Class/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.oreilly.com/catalog/advperl/
COMMENT=	Perl extension for optimized template builder base class

USE_BUILDLINK_ONLY=	YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Class/ObjectTemplate/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../lang/perl5/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
