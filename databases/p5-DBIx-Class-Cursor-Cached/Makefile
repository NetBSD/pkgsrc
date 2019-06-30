# $NetBSD: Makefile,v 1.16 2019/06/30 20:14:23 nia Exp $

DISTNAME=	DBIx-Class-Cursor-Cached-1.001004
PKGNAME=	p5-${DISTNAME:S/00100/1./}
PKGREVISION=	2
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=DBIx/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/DBIx-Class-Cursor-Cached
COMMENT=	Cursor class with built-in caching support
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-DBIx-Class>=0.08124:../../databases/p5-DBIx-Class
DEPENDS+=	p5-DBD-SQLite>=1.25:../../databases/p5-DBD-SQLite
DEPENDS+=	p5-Carp-Clan>=6.0:../../devel/p5-Carp-Clan

BUILD_DEPENDS+=	p5-Cache-Cache-[0-9]*:../../devel/p5-Cache-Cache

USE_LANGUAGES=		# empty
MAKE_ENV+=		PERL_USE_UNSAFE_INC=1
PERL5_PACKLIST=		auto/DBIx/Class/Cursor/Cached/.packlist
PERL5_MODULE_TYPE=	Module::Install::Bundled

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
