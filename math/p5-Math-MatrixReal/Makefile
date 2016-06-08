# $NetBSD: Makefile,v 1.26 2016/06/08 19:24:02 wiz Exp $

DISTNAME=	Math-MatrixReal-2.12
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
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
