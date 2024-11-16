# $NetBSD: Makefile,v 1.3 2024/11/16 12:05:08 wiz Exp $

DISTNAME=		Syntax-Keyword-Try-0.29
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		1
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=../../authors/id/P/PE/PEVANS/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://metacpan.org/pod/Syntax::Keyword::Try
COMMENT=		Add try/catch/finally syntax to Perl
LICENSE=		${PERL5_LICENSE}

TEST_DEPENDS+=		p5-Test2-Suite-[0-9]*:../../devel/p5-Test2-Suite

PERL5_PACKLIST=		auto/Syntax/Keyword/Try/.packlist
PERL5_MODULE_TYPE=	Module::Build

.include "../../devel/p5-XS-Parse-Keyword/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
