# $NetBSD: Makefile,v 1.14 2019/08/11 13:19:48 wiz Exp $
#

DISTNAME=	Mixin-ExtraFields-Param-0.021
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	5
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/R/RJ/RJBS/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Mixin-ExtraFields-Param
COMMENT=	Perl 5 module to make your class provide a familiar "param" method
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=		# empty

DEPENDS+=	p5-Mixin-ExtraFields>=0.002:../../devel/p5-Mixin-ExtraFields
DEPENDS+=	p5-Sub-Exporter>=0.900:../../devel/p5-Sub-Exporter

PERL5_PACKLIST=	auto/Mixin/ExtraFields/Param/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
