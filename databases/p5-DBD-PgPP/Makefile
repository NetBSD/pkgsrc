# $NetBSD: Makefile,v 1.3 2008/10/19 19:17:44 he Exp $
#

DISTNAME=	DBD-PgPP-0.05
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	databases
MASTER_SITES=	http://search.cpan.org/CPAN/authors/id/A/AR/ARC/

MAINTAINER=	ficovh@yahoo.com
HOMEPAGE=	http://search.cpan.org/CPAN/authors/id/A/AR/ARC/
COMMENT=	DBD::PgPP - Pure Perl PostgreSQL driver for the DBI

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-DBI>=0:../../databases/p5-DBI

PERL5_PACKLIST=	auto/DBD/PgPP/.packlist
USE_LANGUAGES=	# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
