# $NetBSD: Makefile,v 1.18 2023/07/06 09:38:08 wiz Exp $

DISTNAME=	Archive-Peek-0.37
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	archivers perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Archive/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Archive-Peek
COMMENT=	Perl5 module to peek into archives without extracting them
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Archive-Zip-[0-9]*:../../archivers/p5-Archive-Zip
DEPENDS+=	p5-Moo-[0-9]*:../../devel/p5-Moo
DEPENDS+=	p5-Types-Path-Tiny-[0-9]*:../../devel/p5-Types-Path-Tiny

# for make test
TEST_DEPENDS+=	p5-Package-DeprecationManager-[0-9]*:../../devel/p5-Package-DeprecationManager
TEST_DEPENDS+=	p5-Test-Pod-[0-9]*:../../devel/p5-Test-Pod

PERL5_PACKLIST=		auto/Archive/Peek/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
