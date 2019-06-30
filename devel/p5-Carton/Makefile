# $NetBSD: Makefile,v 1.3 2019/06/30 20:14:37 nia Exp $

DISTNAME=	Carton-v1.0.34
PKGNAME=	p5-${DISTNAME:S/-v/-/}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/M/MI/MIYAGAWA/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/carton
COMMENT=	Perl module dependency manager (aka Bundler for Perl)
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Menlo-Legacy-[0-9]*:../../devel/p5-Menlo-Legacy
DEPENDS+=	p5-Path-Tiny-[0-9]*:../../filesystems/p5-Path-Tiny

PERL5_PACKLIST=	auto/Carton/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
