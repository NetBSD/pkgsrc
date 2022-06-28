# $NetBSD: Makefile,v 1.27 2022/06/28 11:31:25 wiz Exp $

DISTNAME=	DBIx-DBSchema-0.45
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	7
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=DBIx/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/DBIx-DBSchema
COMMENT=	Database-independent schema objects
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-FreezeThaw-[0-9]*:../../devel/p5-FreezeThaw

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/DBIx/DBSchema/.packlist

.include "../../databases/p5-DBI/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
