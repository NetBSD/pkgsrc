# $NetBSD: Makefile,v 1.32 2026/07/16 19:02:49 wiz Exp $

DISTNAME=	Module-Find-0.17
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
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
