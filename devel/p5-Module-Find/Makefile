# $NetBSD: Makefile,v 1.23 2020/04/16 11:26:20 mef Exp $

DISTNAME=	Module-Find-0.15
PKGNAME=	p5-${DISTNAME}
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
