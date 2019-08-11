# $NetBSD: Makefile,v 1.9 2019/08/11 13:19:11 wiz Exp $

DISTNAME=		Data-Random-0.13
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		2
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Data/}

MAINTAINER=		phil@cs.wwu.edu
HOMEPAGE=		https://metacpan.org/release/Data-Random
COMMENT=		Perl module to generate random data
LICENSE=		${PERL5_LICENSE}

DEPENDS+=		p5-GD>=1.18:../../graphics/p5-GD
DEPENDS+=		p5-Time-Piece>=1.16:../../time/p5-Time-Piece
BUILD_DEPENDS+=		p5-YAML-Tiny-[0-9]*:../../textproc/p5-YAML-Tiny
BUILD_DEPENDS+=		p5-File-ShareDir-Install-[0-9]*:../../devel/p5-File-ShareDir-Install
TEST_DEPENDS+=		p5-Test-MockTime-[0-9]*:../../time/p5-Test-MockTime

MAKE_ENV+=	PERL_USE_UNSAFE_INC=1
PERL5_PACKLIST=	auto/Data/Random/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
