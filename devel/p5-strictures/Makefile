# $NetBSD: Makefile,v 1.20 2017/06/05 14:23:55 ryoon Exp $

DISTNAME=	strictures-2.000003
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/H/HA/HAARG/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/strictures/
COMMENT=	Perl 5 pragma to turn on strict and make all warnings fatal
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/strictures/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
