# $NetBSD: Makefile,v 1.9 2015/02/08 02:56:20 mef Exp $
#

DISTNAME=	IO-TieCombine-1.004
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=IO/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/IO-TieCombine/
COMMENT=	Perl 5 module to produce tied separate but combined variables
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST= auto/IO/TieCombine/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
