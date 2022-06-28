# $NetBSD: Makefile,v 1.21 2022/06/28 11:32:03 wiz Exp $

DISTNAME=	Class-Mix-0.006
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	5
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Class/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Class-Mix
COMMENT=	Perl 5 module providing dynamic class mixing
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Params-Classify-[0-9]*:../../devel/p5-Params-Classify
#DEPENDS+=	{perl>=5.10.1,p5-parent-[0-9]*}:../../devel/p5-parent

USE_LANGUAGES=		# empty
PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/Class/Mix/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
