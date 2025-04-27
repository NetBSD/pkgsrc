# $NetBSD: Makefile,v 1.6 2025/04/27 05:19:47 wiz Exp $

DISTNAME=	meta-0.013
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	https://cpan.metacpan.org/authors/id/P/PE/PEVANS/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/dist/meta
COMMENT=	Perl module for meta-programming
LICENSE=	${PERL5_LICENSE}

TEST_DEPENDS+=	p5-Test2-Suite-[0-9]*:../../devel/p5-Test2-Suite

PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/meta/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
