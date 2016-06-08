# $NetBSD: Makefile,v 1.42 2016/06/08 19:22:34 wiz Exp $

DISTNAME=	App-cpanminus-1.7042
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=App/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/App-cpanminus/
COMMENT=	Perl5 script to get, unpack, build and install modules from CPAN
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/App/cpanminus/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
