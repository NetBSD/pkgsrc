# $NetBSD: Makefile,v 1.4 2011/08/14 08:18:07 obache Exp $
#

DISTNAME=	DBIx-Connector-0.40
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=DBIx/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/DBIx-Connector/
COMMENT=	Fast, safe DBI connection and transaction management
LICENSE=	${PERL5_LICENSE}

BUILD_DEPENDS+=	p5-Test-MockModule>=0.05:../../devel/p5-Test-MockModule

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/DBIx/Connector/.packlist
PERL5_MODULE_TYPE=	Module::Build

BUILDLINK_API_DEPENDS.p5-DBI+=	p5-DBI>=1.614
.include "../../databases/p5-DBI/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
