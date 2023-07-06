# $NetBSD: Makefile,v 1.8 2023/07/06 09:40:12 wiz Exp $

DISTNAME=	Test-Exit-0.11
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	5
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/A/AR/ARODLAND/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/pod/Test::Exit
COMMENT=	Test that some code calls exit() without terminating testing
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Return-MultiLevel-[0-9]*:../../devel/p5-Return-MultiLevel

PERL5_PACKLIST=	auto/Test/Exit/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
