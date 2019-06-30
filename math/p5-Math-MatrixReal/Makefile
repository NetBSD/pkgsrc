# $NetBSD: Makefile,v 1.30 2019/06/30 20:16:19 nia Exp $

DISTNAME=	Math-MatrixReal-2.13
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	math perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Math/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Math-MatrixReal
COMMENT=	Perl module for performing operations on real matrices
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Math/MatrixReal/.packlist
PERL5_MODULE_TYPE=	Module::Build

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
