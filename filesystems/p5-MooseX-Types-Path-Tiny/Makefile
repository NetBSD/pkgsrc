# $NetBSD: Makefile,v 1.17 2023/06/06 12:41:22 riastradh Exp $

DISTNAME=	MooseX-Types-Path-Tiny-0.012
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	5
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=MooseX/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/MooseX-Types-Path-Tiny
COMMENT=	Path::Tiny types and coercions for Moose
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Moose>=2:../../devel/p5-Moose
DEPENDS+=	p5-MooseX-Getopt-[0-9]*:../../devel/p5-MooseX-Getopt
DEPENDS+=	p5-MooseX-Types-[0-9]*:../../devel/p5-MooseX-Types
DEPENDS+=	p5-MooseX-Types-Stringlike-[0-9]*:../../devel/p5-MooseX-Types-Stringlike
DEPENDS+=	p5-Path-Tiny-[0-9]*:../../filesystems/p5-Path-Tiny
# for make test
TOOL_DEPENDS+=	p5-File-pushd-[0-9]*:../../devel/p5-File-pushd
TOOL_DEPENDS+=	p5-Package-DeprecationManager-[0-9]*:../../devel/p5-Package-DeprecationManager

PERL5_MODULE_TYPE=	Module::Build::Tiny
USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/MooseX/Types/Path/Tiny/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
