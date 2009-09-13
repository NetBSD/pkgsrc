# $NetBSD: Makefile,v 1.7 2009/09/13 20:40:00 sno Exp $

DISTNAME=	Catalyst-Model-DBIC-Schema-0.29
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Catalyst/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Catalyst-Model-DBIC-Schema/
COMMENT=	DBIx::Class::Schema Model Class
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Carp-Clan-[0-9]*:../../devel/p5-Carp-Clan
DEPENDS+=	p5-Catalyst-Runtime>=5.80005:../../www/p5-Catalyst-Runtime
DEPENDS+=	p5-CatalystX-Component-Traits>=0.10:../../www/p5-CatalystX-Component-Traits
DEPENDS+=	p5-Class-Accessor-Grouped>=0.09000:../../devel/p5-Class-Accessor-Grouped
DEPENDS+=	p5-DBIx-Class>=0.08111:../../databases/p5-DBIx-Class
DEPENDS+=	p5-List-MoreUtils-[0-9]*:../../devel/p5-List-MoreUtils
DEPENDS+=	p5-Moose-[0-9]*:../../devel/p5-Moose
DEPENDS+=	p5-Moose-Autobox-[0-9]*:../../devel/p5-Moose-Autobox
DEPENDS+=	p5-MooseX-Types-[0-9]*:../../devel/p5-MooseX-Types
DEPENDS+=	p5-Tie-IxHash-[0-9]*:../../devel/p5-Tie-IxHash
DEPENDS+=	p5-namespace-autoclean-[0-9]*:../../devel/p5-namespace-autoclean

# Recommended / Feature
# Catalyst::Helper support
DEPENDS+=	p5-Catalyst-Devel>=1:../../www/p5-Catalyst-Devel
DEPENDS+=	p5-DBIx-Class-Schema-Loader>=0.04005:../../databases/p5-DBIx-Class-Schema-Loader
# Caching support
DEPENDS+=	p5-DBIx-Class-Cursor-Cached-[0-9]*:../../databases/p5-DBIx-Class-Cursor-Cached
# Replication Support
DEPENDS+=	p5-MooseX-AttributeHelpers-[0-9]*:../../devel/p5-MooseX-AttributeHelpers
DEPENDS+=	p5-Hash-Merge-[0-9]*:../../devel/p5-Hash-Merge

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Catalyst/Model/DBIC/Schema/.packlist
PERL5_MODULE_TYPE=	Module::Install

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
