# $NetBSD: Makefile,v 1.12 2022/06/28 11:32:49 wiz Exp $

DISTNAME=	MooX-ClassAttribute-0.011
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	6
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/T/TO/TOBYINK/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/pod/MooX::ClassAttribute
COMMENT=	Declare class attributes Moose-style... but without Moose
LICENSE=	${PERL5_LICENSE}

# for make test
BUILD_DEPENDS+=	p5-MooseX-ClassAttribute-[0-9]*:../../devel/p5-MooseX-ClassAttribute
BUILD_DEPENDS+=	p5-Moo-[0-9]*:../../devel/p5-Moo
BUILD_DEPENDS+=	p5-Exporter-Tiny-[0-9]*:../../devel/p5-Exporter-Tiny

PERL5_PACKLIST=	auto/MooX/ClassAttribute/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
