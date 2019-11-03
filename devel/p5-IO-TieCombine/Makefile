# $NetBSD: Makefile,v 1.17 2019/11/03 10:15:55 rillig Exp $
#

DISTNAME=	IO-TieCombine-1.005
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=IO/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/IO-TieCombine
COMMENT=	Perl 5 module to produce tied separate but combined variables
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=	auto/IO/TieCombine/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
