# $NetBSD: Makefile,v 1.25 2023/07/06 09:38:22 wiz Exp $
#

DISTNAME=	DBIx-Abstract-1.04
PKGNAME=	p5-${DISTNAME}00
PKGREVISION=	9
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=DBIx/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/DBIx-Abstract
COMMENT=	SQL Database access functions
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Check-ISA-[0-9]*:../../devel/p5-Check-ISA
DEPENDS+=	p5-DBI-[0-9]*:../../databases/p5-DBI

TOOL_DEPENDS+=	p5-DBD-SQLite-[0-9]*:../../databases/p5-DBD-SQLite

PERL5_PACKLIST=		auto/DBIx/Abstract/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
