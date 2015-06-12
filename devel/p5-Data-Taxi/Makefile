# $NetBSD: Makefile,v 1.11 2015/06/12 10:49:06 wiz Exp $

DISTNAME=	Data-Taxi-0.96
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Data/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Data-Taxi/
COMMENT=	Perl 5 module providing taint-aware, XML-ish data serialization
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Data/Taxi/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
