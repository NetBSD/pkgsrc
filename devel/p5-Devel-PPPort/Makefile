# $NetBSD: Makefile,v 1.33 2019/06/30 20:14:55 nia Exp $

DISTNAME=	Devel-PPPort-3.52
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/A/AT/ATOOMIC/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Devel-PPPort
COMMENT=	Perl5 module to bring newer features to older perl
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=	c
PERL5_PACKLIST=	auto/Devel/PPPort/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
