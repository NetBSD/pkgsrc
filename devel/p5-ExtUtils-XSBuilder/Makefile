# $NetBSD: Makefile,v 1.28 2023/07/06 09:39:08 wiz Exp $

DISTNAME=	ExtUtils-XSBuilder-0.28
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	15
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=ExtUtils/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/ExtUtils-XSBuilder
COMMENT=	Perl5 module for automatic XS glue code generation
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Parse-RecDescent-[0-9]*:../../devel/p5-Parse-RecDescent
DEPENDS+=	p5-Tie-IxHash-[0-9]*:../../devel/p5-Tie-IxHash

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/ExtUtils/XSBuilder/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
