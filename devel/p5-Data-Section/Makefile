# $NetBSD: Makefile,v 1.1.1.1 2008/10/30 23:36:03 he Exp $
#

DISTNAME=	Data-Section-0.005
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Data/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Data-Section/
COMMENT=	Perl 5 module to read multiple hunks of data out of your DATA section

DEPENDS+=	p5-Class-ISA>0:../../devel/p5-Class-ISA
DEPENDS+=	p5-Sub-Exporter>=0.979:../../devel/p5-Sub-Exporter

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=	auto/Data/Section/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
