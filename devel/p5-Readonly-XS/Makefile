# $NetBSD: Makefile,v 1.22 2023/07/06 09:39:56 wiz Exp $
#

DISTNAME=	Readonly-XS-1.05
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	14
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Readonly/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Readonly-XS
COMMENT=	Perl 5 companion module to the Readonly module

DEPENDS+=	p5-Readonly>=1.02:../../devel/p5-Readonly

PERL5_PACKLIST=	auto/Readonly/XS/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
