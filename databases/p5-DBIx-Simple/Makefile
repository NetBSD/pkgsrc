# $NetBSD: Makefile,v 1.2 2024/11/16 12:03:27 wiz Exp $

DISTNAME=		DBIx-Simple-1.37
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		1
CATEGORIES=		databases perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=DBIx/}

MAINTAINER=		ficovh@yahoo.com
HOMEPAGE=		https://metacpan.org/pod/DBIx::Simple
COMMENT=		Very complete easy-to-use OO interface to DBI
LICENSE=		${PERL5_LICENSE}

DEPENDS+=		p5-DBI>=1.21:../../databases/p5-DBI

PERL5_PACKLIST=		auto/DBIx/Simple/.packlist
USE_LANGUAGES=		# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
