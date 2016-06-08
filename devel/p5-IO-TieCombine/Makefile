# $NetBSD: Makefile,v 1.12 2016/06/08 19:23:04 wiz Exp $
#

DISTNAME=	IO-TieCombine-1.005
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=IO/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/IO-TieCombine/
COMMENT=	Perl 5 module to produce tied separate but combined variables
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST= auto/IO/TieCombine/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
