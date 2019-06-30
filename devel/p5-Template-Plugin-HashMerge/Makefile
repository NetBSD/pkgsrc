# $NetBSD: Makefile,v 1.12 2019/06/30 20:15:47 nia Exp $
#

DISTNAME=	Template-Plugin-HashMerge-0.01
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	9
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Template/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Template-Plugin-HashMerge
COMMENT=	TT2 plugin to use Hash::Merge
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=		# empty

DEPENDS+=	p5-Hash-Merge>=0.09:../../devel/p5-Hash-Merge
DEPENDS+=	p5-Template-Plugin-VMethods>=0.02:../../devel/p5-Template-Plugin-VMethods
DEPENDS+=	p5-Template-Toolkit>=2.20:../../www/p5-Template-Toolkit

PERL5_PACKLIST=		auto/Template/Plugin/HashMerge/.packlist
PERL5_MODULE_TYPE=	Module::Build

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
