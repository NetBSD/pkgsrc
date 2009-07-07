# $NetBSD: Makefile,v 1.2 2009/07/07 22:38:10 sno Exp $
#

DISTNAME=	Data-Section-0.091820
PKGNAME=	p5-${DISTNAME:S/091820/091.820/}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Data/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Data-Section/
COMMENT=	Perl 5 module to read multiple hunks of data out of your DATA section
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Class-ISA>0:../../devel/p5-Class-ISA
DEPENDS+=	p5-Sub-Exporter>=0.979:../../devel/p5-Sub-Exporter

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=	auto/Data/Section/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
