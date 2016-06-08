# $NetBSD: Makefile,v 1.14 2016/06/08 19:23:27 wiz Exp $
#

DISTNAME=	Readonly-XS-1.05
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	7
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Readonly/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Readonly-XS/
COMMENT=	Perl 5 companion module to the Readonly module

DEPENDS+=	p5-Readonly>=1.02:../../devel/p5-Readonly

PERL5_PACKLIST=	auto/Readonly/XS/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
