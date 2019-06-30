# $NetBSD: Makefile,v 1.12 2019/06/30 20:14:48 nia Exp $

DISTNAME=	Data-Dumper-Names-0.03
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	9
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Data/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Data-Dumper-Names
COMMENT=	Dump variables with names (no source filter)
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-PadWalker>0.13:../../devel/p5-PadWalker

PERL5_MODULE_TYPE= Module::Build

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Data/Dumper/Names/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
