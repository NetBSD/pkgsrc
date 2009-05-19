# $NetBSD: Makefile,v 1.5 2009/05/19 08:59:06 wiz Exp $
#

DISTNAME=	DBD-PgPP-0.06
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	databases
MASTER_SITES=	http://search.cpan.org/CPAN/authors/id/A/AR/ARC/

MAINTAINER=	ficovh@yahoo.com
HOMEPAGE=	http://search.cpan.org/CPAN/authors/id/A/AR/ARC/
COMMENT=	DBD::PgPP - Pure Perl PostgreSQL driver for the DBI
LICENSE=	artistic-2.0 # OR gnu-gpl-v2+

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=	auto/DBD/PgPP/.packlist
USE_LANGUAGES=	# none

BUILDLINK_API_DEPENDS.p5-DBI+=	p5-DBI>=1.59

.include "../../databases/p5-DBI/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
