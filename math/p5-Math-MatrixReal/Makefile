# $NetBSD: Makefile,v 1.19 2012/09/11 23:04:27 asau Exp $

DISTNAME=	Math-MatrixReal-2.08
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5mmr
CATEGORIES=	math perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Math/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Math-MatrixReal/
COMMENT=	Perl module for performing operations on real matrices
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Math/MatrixReal/.packlist
PERL5_MODULE_TYPE=	Module::Build

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
