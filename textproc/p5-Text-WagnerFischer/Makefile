# $NetBSD: Makefile,v 1.8 2015/06/12 10:51:34 wiz Exp $
#

DISTNAME=	Text-WagnerFischer-0.04
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	5
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Text/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Text-WagnerFischer
COMMENT=	Perl module for configurable edit distance calculations
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Text/WagnerFischer/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
