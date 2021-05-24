# $NetBSD: Makefile,v 1.25 2021/05/24 19:51:03 wiz Exp $

DISTNAME=	Module-Find-0.15
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Module/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Module-Find
COMMENT=	Lets you find and use modules in categories
LICENSE=	${PERL5_LICENSE}

TEST_DEPENDS+=	p5-Test-CPAN-Meta-[0-9]*:../../devel/p5-Test-CPAN-Meta

EXTRACT_USING=	bsdtar
USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Module/Find/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
