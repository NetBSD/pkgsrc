# $NetBSD: Makefile,v 1.8 2011/08/06 20:21:33 adam Exp $

DISTNAME=	DBD-PgPP-0.08
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=DBD/}

MAINTAINER=	ficovh@yahoo.com
HOMEPAGE=	http://search.cpan.org/dist/DBD-PgPP/
COMMENT=	DBD::PgPP - Pure Perl PostgreSQL driver for the DBI
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=	auto/DBD/PgPP/.packlist
USE_LANGUAGES=	# none

BUILDLINK_API_DEPENDS.p5-DBI+=	p5-DBI>=1.59

.include "../../databases/p5-DBI/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
