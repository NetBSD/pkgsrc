# $NetBSD: Makefile,v 1.17 2018/08/22 09:43:16 wiz Exp $

DISTNAME=	DBIx-Class-Candy-0.005003
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=DBIx/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/DBIx-Class-Candy/
COMMENT=	Perl5 modules to simplify the common case stuff for DBIx::Class
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-DBIx-Class>=0.08123:../../databases/p5-DBIx-Class
DEPENDS+=	p5-Lingua-EN-Inflect-[0-9]*:../../textproc/p5-Lingua-EN-Inflect
DEPENDS+=	p5-MRO-Compat>=0.11:../../devel/p5-MRO-Compat
DEPENDS+=	p5-Sub-Exporter>=0.982:../../devel/p5-Sub-Exporter
DEPENDS+=	p5-namespace-clean>=0.18:../../devel/p5-namespace-clean

BUILD_DEPENDS+=	p5-Test-Deep-[0-9]*:../../devel/p5-Test-Deep
BUILD_DEPENDS+=	p5-Test-Fatal-[0-9]*:../../devel/p5-Test-Fatal

PERL5_PACKLIST=		auto/DBIx/Class/Candy/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
