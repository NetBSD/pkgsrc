# $NetBSD: Makefile,v 1.35 2023/07/06 09:38:19 wiz Exp $

DISTNAME=	Catalyst-Model-DBIC-Schema-0.65
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	9
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Catalyst/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Catalyst-Model-DBIC-Schema
COMMENT=	DBIx::Class::Schema Model Class
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Carp-Clan-[0-9]*:../../devel/p5-Carp-Clan
DEPENDS+=	p5-Catalyst-Runtime>=5.80005:../../www/p5-Catalyst-Runtime
DEPENDS+=	p5-CatalystX-Component-Traits>=0.14:../../www/p5-CatalystX-Component-Traits
DEPENDS+=	p5-DBIx-Class>=0.08114:../../databases/p5-DBIx-Class
DEPENDS+=	p5-List-MoreUtils-[0-9]*:../../devel/p5-List-MoreUtils
DEPENDS+=	p5-Moose>=0.90:../../devel/p5-Moose
DEPENDS+=	p5-MooseX-NonMoose>=0.16:../../devel/p5-MooseX-NonMoose
DEPENDS+=	p5-MooseX-Types-[0-9]*:../../devel/p5-MooseX-Types
DEPENDS+=	p5-MooseX-Types-LoadableClass>=0.009:../../devel/p5-MooseX-Types-LoadableClass
DEPENDS+=	p5-Module-Runtime>=0.012:../../devel/p5-Module-Runtime
DEPENDS+=	p5-Tie-IxHash-[0-9]*:../../devel/p5-Tie-IxHash
DEPENDS+=	p5-namespace-autoclean-[0-9]*:../../devel/p5-namespace-autoclean

# Recommended / Feature
# Catalyst::Helper support
DEPENDS+=	p5-Catalyst-Devel>=1:../../www/p5-Catalyst-Devel
DEPENDS+=	p5-DBIx-Class-Schema-Loader>=0.04005:../../databases/p5-DBIx-Class-Schema-Loader
# Caching support
DEPENDS+=	p5-DBIx-Class-Cursor-Cached-[0-9]*:../../databases/p5-DBIx-Class-Cursor-Cached
# Replication Support
DEPENDS+=	p5-Hash-Merge-[0-9]*:../../devel/p5-Hash-Merge
DEPENDS+=	p5-namespace-clean-[0-9]*:../../devel/p5-namespace-clean

#TOOL_DEPENDS+=	{perl>=5.12.0,p5-Test-Simple>=0.94}:../../devel/p5-Test-Simple

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Catalyst/Model/DBIC/Schema/.packlist
PERL5_MODULE_TYPE=	Module::Install::Bundled

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
