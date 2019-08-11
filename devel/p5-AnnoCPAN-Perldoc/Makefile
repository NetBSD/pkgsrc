# $NetBSD: Makefile,v 1.13 2019/08/11 13:18:49 wiz Exp $

DISTNAME=	AnnoCPAN-Perldoc-0.10
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	10
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/I/IT/ITUB/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/AnnoCPAN-Perldoc
COMMENT=	Integrate AnnoCPAN notes locally into perldoc
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/AnnoCPAN/Perldoc/.packlist

DEPENDS+=	p5-DBD-SQLite>=1:../../databases/p5-DBD-SQLite
DEPENDS+=	p5-DBI>=0:../../databases/p5-DBI
DEPENDS+=	p5-IO-String>=0:../../devel/p5-IO-String

# For test target
BUILD_DEPENDS+=	p5-Test-Pod-[0-9]*:../../devel/p5-Test-Pod

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
