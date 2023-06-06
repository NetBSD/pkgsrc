# $NetBSD: Makefile,v 1.13 2023/06/06 12:40:54 riastradh Exp $

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
TOOL_DEPENDS+=	p5-MooseX-ClassAttribute-[0-9]*:../../devel/p5-MooseX-ClassAttribute
TOOL_DEPENDS+=	p5-Moo-[0-9]*:../../devel/p5-Moo
TOOL_DEPENDS+=	p5-Exporter-Tiny-[0-9]*:../../devel/p5-Exporter-Tiny

PERL5_PACKLIST=	auto/MooX/ClassAttribute/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
